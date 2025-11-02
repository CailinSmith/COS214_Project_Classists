# =========================
# Project Configuration
# =========================
MAKEFLAGS += -j8 #add numeber to the j to limit the number of cores e.g. -j4
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude -Isrc
BUILD_DIR := build
SRC_DIR := src
TEST_DIR := testing

# Dependencies folder (absolute path for Makefile safety)
DEPS_DIR := $(CURDIR)/.deps

# FTXUI Configuration
FTXUI_SRC := $(DEPS_DIR)/ftxui_src
FTXUI_BUILD := $(DEPS_DIR)/ftxui_build
FTXUI_INSTALL := $(DEPS_DIR)/ftxui_install
FTXUI_INCLUDE := $(FTXUI_INSTALL)/include
FTXUI_LIB := $(FTXUI_INSTALL)/lib
# Note: We'll add quotes in the recipes where this is used
FTXUI_LIBS := -lftxui-component -lftxui-dom -lftxui-screen

# =========================
# Targets
# =========================
TARGET := $(BUILD_DIR)/main
GUI_TARGET := $(BUILD_DIR)/gui
TEST_TARGET := $(BUILD_DIR)/test_runner

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
MAIN_SRCS := $(filter-out $(SRC_DIR)/gui.cpp,$(SRCS))
OBJS := $(MAIN_SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

CORE_OBJS := $(filter-out $(BUILD_DIR)/main.o,$(OBJS))

# GUI objects (all core objects + gui.o)
GUI_OBJS := $(CORE_OBJS) $(BUILD_DIR)/gui.o

TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS := $(TEST_SRCS:$(TEST_DIR)/%.cpp=$(BUILD_DIR)/%.test.o)

# Demo program (kept outside src/ so it won't be picked up by the src/*.cpp wildcard)
DEMO_SRC := demos/demo.cpp
DEMO_OBJ := $(BUILD_DIR)/demo_demo.o

# =========================
# Default target
# =========================
# Default: build only CLI
default: setup $(TARGET)

# Build everything: CLI, GUI, and demo
all: setup $(TARGET) $(GUI_TARGET) demo

# =========================
# Build main project
# =========================
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# =========================
# Build GUI application
# =========================
$(GUI_TARGET): check-ftxui $(GUI_OBJS)
	$(CXX) $(CXXFLAGS) -I"$(FTXUI_INCLUDE)" -o $@ $(GUI_OBJS) -L"$(FTXUI_LIB)" $(FTXUI_LIBS)

$(BUILD_DIR)/gui.o: $(SRC_DIR)/gui.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I"$(FTXUI_INCLUDE)" -c $< -o $@

check-ftxui:
	@if [ ! -d "$(FTXUI_INSTALL)/lib" ] || [ ! -f "$(FTXUI_INSTALL)/lib/libftxui-screen.a" ]; then \
		echo "ERROR: FTXUI libraries not found!"; \
		echo ""; \
		echo "Run: make install-deps"; \
		echo ""; \
		exit 1; \
	fi

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =========================
# Unit Tests
# =========================
$(TEST_TARGET): $(CORE_OBJS) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.test.o: $(TEST_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build demo object
$(BUILD_DIR)/demo_demo.o: $(DEMO_SRC)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Integration tests (WSL-friendly runner)
.PHONY: itests
itests: setup $(TARGET)
	# Run the integration test for case2 (WSL / bash runner)
	./tests/run_and_check.sh case2

# Demo target: link project core objects with a small demo main
.PHONY: demo
demo: $(CORE_OBJS) $(DEMO_OBJ)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/demo $^

# =========================
# Run CLI application
# =========================
runcli: setup demo
	./$(BUILD_DIR)/demo

# =========================
# Run main binary
# =========================
run: $(TARGET)
	./$(TARGET)

# =========================
# Run GUI application
# =========================
rungui: setup $(GUI_TARGET)
	./$(GUI_TARGET)

# =========================
# Memory check with Valgrind
# =========================
# Run valgrind on both main and unit tests
.PHONY: val-all
val-all: $(TARGET) $(TEST_TARGET)
	@echo "Running valgrind on unit tests ($(TEST_TARGET))"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./$(TEST_TARGET)
	@echo ""
	@echo "Running valgrind on main executable ($(TARGET))"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./$(TARGET)

# Run valgrind only on unit tests (test runner)
.PHONY: val-test
val-test: $(TEST_TARGET)
	@echo "Running valgrind on unit tests ($(TEST_TARGET))"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_TARGET)

# Run valgrind only on main executable
.PHONY: val-main
val-main: $(TARGET)
	@echo "Running valgrind on main executable ($(TARGET))"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

.PHONY: val-gui
val-gui: $(GUI_TARGET)
	@echo "Running valgrind on GUI application ($(GUI_TARGET))"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(GUI_TARGET)

.PHONY: val-cli
val-cli: setup demo
	@echo "Running valgrind on CLI demo application ($(BUILD_DIR)/demo)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(BUILD_DIR)/demo


# =========================
# Checkout Memory Test
# =========================
CHECKOUT_TEST_SRC := tests/test_checkout_memory.cpp
CHECKOUT_TEST_OBJ := $(BUILD_DIR)/test_checkout_memory.o
CHECKOUT_TEST_TARGET := $(BUILD_DIR)/test_checkout_memory

$(CHECKOUT_TEST_TARGET): $(CORE_OBJS) $(CHECKOUT_TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(CHECKOUT_TEST_OBJ): $(CHECKOUT_TEST_SRC)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: test-checkout
test-checkout: $(CHECKOUT_TEST_TARGET)
	./$(CHECKOUT_TEST_TARGET)

.PHONY: val-checkout
val-checkout: $(CHECKOUT_TEST_TARGET)
	@echo "Running valgrind on checkout memory test"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(CHECKOUT_TEST_TARGET)

# =========================
# Decorated Checkout Memory Test
# =========================
DECORATED_TEST_SRC := tests/test_decorated_checkout.cpp
DECORATED_TEST_OBJ := $(BUILD_DIR)/test_decorated_checkout.o
DECORATED_TEST_TARGET := $(BUILD_DIR)/test_decorated_checkout

$(DECORATED_TEST_TARGET): $(CORE_OBJS) $(DECORATED_TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(DECORATED_TEST_OBJ): $(DECORATED_TEST_SRC)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: test-decorated
test-decorated: $(DECORATED_TEST_TARGET)
	./$(DECORATED_TEST_TARGET)

.PHONY: val-decorated
val-decorated: $(DECORATED_TEST_TARGET)
	@echo "Running valgrind on decorated checkout memory test"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(DECORATED_TEST_TARGET)

# Run all memory tests
.PHONY: test-memory
test-memory: test-checkout test-decorated

.PHONY: val-memory
val-memory: val-checkout val-decorated

# =========================
# Setup / Clean
# =========================
setup:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

clean-all: clean
	rm -rf "$(DEPS_DIR)"

# =========================
# Doxygen Documentation
# =========================
DOCS_DIR := doxygen

# Install Doxygen
install-doxygen:
	@if ! command -v doxygen >/dev/null 2>&1; then \
		echo "Installing Doxygen..."; \
		if command -v apt-get >/dev/null 2>&1; then \
			sudo apt-get update && sudo apt-get install -y doxygen graphviz; \
		elif command -v dnf >/dev/null 2>&1; then \
			sudo dnf install -y doxygen graphviz; \
		elif command -v brew >/dev/null 2>&1; then \
			brew install doxygen graphviz; \
		elif command -v pacman >/dev/null 2>&1; then \
			sudo pacman -S doxygen graphviz; \
		else \
			echo "ERROR: Unable to detect package manager!"; \
			echo "Please install doxygen and graphviz manually:"; \
			echo "  Ubuntu/Debian: sudo apt-get install doxygen graphviz"; \
			echo "  Fedora/RHEL:   sudo dnf install doxygen graphviz"; \
			echo "  macOS:         brew install doxygen graphviz"; \
			echo "  Arch Linux:    sudo pacman -S doxygen graphviz"; \
			exit 1; \
		fi; \
		echo "Doxygen installed successfully!"; \
	else \
		echo "Doxygen is already installed."; \
	fi

# Generate Doxygen documentation
doxygen:
	@if ! command -v doxygen >/dev/null 2>&1; then \
		echo "ERROR: Doxygen is not installed!"; \
		echo "Run: make install-doxygen"; \
		exit 1; \
	fi
	@echo "Generating Doxygen documentation..."
	@mkdir -p $(DOCS_DIR)
	doxygen Doxyfile
	@echo "Documentation generated in $(DOCS_DIR)/html/"
	@echo "Open $(DOCS_DIR)/html/index.html in your browser to view."

# Clean Doxygen documentation
clean-doxygen:
	@echo "Removing Doxygen documentation..."
	rm -rf $(DOCS_DIR)
	@echo "Documentation removed."

# =========================
# Install Dependencies
# =========================
install-deps:
	@if ! command -v cmake >/dev/null 2>&1; then \
		echo "ERROR: cmake is not installed!"; \
		echo "Please install cmake first:"; \
		echo "  Ubuntu/Debian: sudo apt-get install cmake g++ git build-essential"; \
		echo "  Fedora/RHEL:   sudo dnf install cmake gcc-c++ git make"; \
		echo "  macOS:         brew install cmake"; \
		exit 1; \
	fi
	@if ! command -v g++ >/dev/null 2>&1; then \
		echo "ERROR: g++ is not installed!"; \
		echo "Please install g++ first:"; \
		echo "  Ubuntu/Debian: sudo apt-get install g++ build-essential"; \
		echo "  Fedora/RHEL:   sudo dnf install gcc-c++"; \
		echo "  macOS:         xcode-select --install"; \
		exit 1; \
	fi
	@if ! command -v git >/dev/null 2>&1; then \
		echo "ERROR: git is not installed!"; \
		echo "Please install git first:"; \
		echo "  Ubuntu/Debian: sudo apt-get install git"; \
		echo "  Fedora/RHEL:   sudo dnf install git"; \
		echo "  macOS:         brew install git"; \
		exit 1; \
	fi
	@if ! command -v chafa >/dev/null 2>&1; then \
		echo "WARNING: chafa is not installed!"; \
		echo "The GUI requires chafa for image rendering."; \
		echo "Please install chafa:"; \
		echo "  Ubuntu/Debian: sudo apt-get install chafa"; \
		echo "  Fedora/RHEL:   sudo dnf install chafa"; \
		echo "  macOS:         brew install chafa"; \
		echo "  Arch Linux:    sudo pacman -S chafa"; \
		echo ""; \
		echo "Continuing with FTXUI installation..."; \
		echo ""; \
	fi
	@if [ ! -d "$(FTXUI_INSTALL)/lib" ] || [ ! -f "$(FTXUI_INSTALL)/lib/libftxui-screen.a" ]; then \
		mkdir -p "$(DEPS_DIR)"; \
		if [ ! -d "$(FTXUI_SRC)" ]; then \
			echo "Cloning FTXUI repository..."; \
			git clone https://github.com/ArthurSonzogni/FTXUI.git "$(FTXUI_SRC)" || exit 1; \
		fi; \
		echo "Building FTXUI (this may take a few minutes)..."; \
		mkdir -p "$(FTXUI_BUILD)" && \
		mkdir -p "$(FTXUI_INSTALL)" && \
		cd "$(FTXUI_BUILD)" && \
		cmake "$(FTXUI_SRC)" -DCMAKE_INSTALL_PREFIX="$(FTXUI_INSTALL)" && \
		make -j4 && \
		make install && \
		cd "$(CURDIR)" && \
		echo "FTXUI installed successfully!"; \
	else \
		echo "FTXUI is already installed in $(DEPS_DIR)"; \
	fi

gui: setup $(GUI_TARGET)

help:
	@echo ""
	@echo "\033[0;32m============================================================================\033[0m"
	@echo "\033[0;32m                          🌿 GREENS ONLY\033[0m 🌿"
	@echo "\033[0;32m============================================================================\033[0m"
	@echo ""
	@echo "QUICK START:"
	@echo "  make install-deps        Install FTXUI dependencies, only needed for the GUI(run first!)"
	@echo "  make runcli              Build and run the command line interface"
	@echo "  make rungui              Build and run the GUI application"
	@echo ""
	@echo "----------------------------------------------------------------------------"
	@echo "BUILD TARGETS:"
	@echo "----------------------------------------------------------------------------"
	@echo "  make                     Build CLI application only (default)"
	@echo "  make all                 Build everything: CLI, GUI, and demo"
	@echo "  make gui                 Build GUI application only (no run)"
	@echo "  make demo                Build demo executable from demos/demo.cpp"
	@echo ""
	@echo "----------------------------------------------------------------------------"
	@echo "RUN TARGETS:"
	@echo "----------------------------------------------------------------------------"
	@echo "  make rungui              Build and run GUI application"
	@echo "  make runcli              Build and run Command Line Interface"
	@echo ""
	@echo "----------------------------------------------------------------------------"
	@echo "TESTING:"
	@echo "----------------------------------------------------------------------------"
	@echo "  make test                Build and run unit tests"
	@echo "  make itests              Run integration tests (WSL/bash script)"
	@echo ""
	@echo "  Memory Testing (Valgrind):"
	@echo "  make val-all             Run valgrind on main executable and unit tests"
	@echo "  make val-test            Run valgrind on unit tests only"
	@echo "  make val-main            Run valgrind on main executable only"
	@echo "  make val-gui             Run valgrind on GUI application"
	@echo "  make val-cli             Run valgrind on CLI demo application"
	@echo ""
	@echo "----------------------------------------------------------------------------"
	@echo "CLEANUP:"
	@echo "----------------------------------------------------------------------------"
	@echo "  make clean               Remove build/ directory"
	@echo "  make clean-all           Remove build/ and .deps/ (all dependencies)"
	@echo "  make clean-doxygen       Remove generated Doxygen documentation"
	@echo ""
	@echo "----------------------------------------------------------------------------"
	@echo "DOCUMENTATION:"
	@echo "----------------------------------------------------------------------------"
	@echo "  make install-doxygen     Install Doxygen and Graphviz"
	@echo "  make doxygen             Generate HTML documentation from code comments"
	@echo "  make clean-doxygen       Remove all generated documentation"
	@echo ""
	@echo "----------------------------------------------------------------------------"
	@echo "DEPENDENCIES:"
	@echo "----------------------------------------------------------------------------"
	@echo "  make install-deps        Install/build FTXUI from source (~2-3 min)"
	@echo "  make check-ftxui         Verify FTXUI is installed correctly"
	@echo ""
	@echo "----------------------------------------------------------------------------"
	@echo "SYSTEM REQUIREMENTS:"
	@echo "----------------------------------------------------------------------------"
	@echo "  GUI requires:  cmake, g++, git, chafa (for image rendering)"
	@echo "  CLI requires:  g++ only"
	@echo "  Testing:       valgrind (optional, for memory checks)"
	@echo ""
	@echo "  Install on Ubuntu/Debian:"
	@echo "    sudo apt-get install cmake g++ git build-essential chafa valgrind"
	@echo ""
	@echo "----------------------------------------------------------------------------"
	@echo "NOTES:"
	@echo "----------------------------------------------------------------------------"
	@echo "  • FTXUI is installed locally in .deps/ (not system-wide)"
	@echo "  • First build downloads and compiles FTXUI (~2-3 minutes)"
	@echo "  • Use 'make clean-all' to remove all dependencies"
	@echo "  • Parallel builds enabled with -j4 (modify MAKEFLAGS for more cores)"
	@echo "  • Main CLI application works without GUI dependencies"
	@echo ""
	@echo "\033[1;32m============================================================================\033[0m"
	@echo "\033[1;32m              Thanks for checking our project out! \033[0m"
	@echo "\033[1;32m============================================================================\033[0m"
	@echo ""

# =========================
# Phony targets- they tell the makefile these are not files
# =========================

.PHONY: default all clean clean-all test setup install-deps gui check-ftxui run runcli rungui help demo itests val-test val-main val-all val-gui val-cli install-doxygen doxygen clean-doxygen view-docs
