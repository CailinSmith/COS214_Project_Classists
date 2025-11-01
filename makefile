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
# Run demo application
# =========================
rundemo: setup demo
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
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_TARGET)
	@echo ""
	@echo "Running valgrind on main executable ($(TARGET))"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

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
	@echo "  make install-deps        Install FTXUI dependencies (run first!)"
	@echo "  make rungui              Build and run the GUI application"
	@echo "  make run                 Build and run the CLI application"
	@echo "  make rundemo             Build and run the demo/facade application"
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
	@echo "  make run                 Build and run CLI application"
	@echo "  make rungui              Build and run GUI application"
	@echo "  make rundemo             Build and run demo/facade application"
	@echo ""
	@echo "----------------------------------------------------------------------------"
	@echo "TESTING:"
	@echo "----------------------------------------------------------------------------"
	@echo "  make test                Build and run unit tests"
	@echo "  make itests              Run integration tests (WSL/bash script)"
	@echo "  make val-all             Run valgrind on both main and tests"
	@echo "  make val-test            Run valgrind on unit tests only"
	@echo "  make val-main            Run valgrind on main executable only"
	@echo ""
	@echo "----------------------------------------------------------------------------"
	@echo "CLEANUP:"
	@echo "----------------------------------------------------------------------------"
	@echo "  make clean               Remove build/ directory"
	@echo "  make clean-all           Remove build/ and .deps/ (all dependencies)"
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
# Phony targets, they tell the makefile these are not files
# =========================

.PHONY: default all clean clean-all test setup install-deps rungui gui check-ftxui run help demo rundemo itests val-test val-main val-all

