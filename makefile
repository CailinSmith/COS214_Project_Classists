# =========================
# Project Configuration
# =========================
MAKEFLAGS += -j4 #add numeber to the j to limit the number of cores e.g. -j4
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude -Isrc
BUILD_DIR := build
SRC_DIR := src
TEST_DIR := testing

# FTXUI Configuration
FTXUI_INSTALL := ftxui_install
FTXUI_INCLUDE := $(FTXUI_INSTALL)/include
FTXUI_LIB := $(FTXUI_INSTALL)/lib
FTXUI_LIBS := -L$(FTXUI_LIB) -lftxui-component -lftxui-dom -lftxui-screen

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

# Target for running only chainOfResponsibility tests
COR_TEST_TARGET := $(BUILD_DIR)/cor_test


# =========================
# Default target
# =========================
all: setup $(TARGET) $(GUI_TARGET)

# =========================
# Build main project
# =========================
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# =========================
# Build GUI application
# =========================
$(GUI_TARGET): $(GUI_OBJS)
	$(CXX) $(CXXFLAGS) -I$(FTXUI_INCLUDE) -o $@ $^ $(FTXUI_LIBS)

$(BUILD_DIR)/gui.o: $(SRC_DIR)/gui.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(FTXUI_INCLUDE) -c $< -o $@

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

test: $(TEST_TARGET)
	./$(TEST_TARGET)

# =========================
# Run main binary
# =========================
run: $(TARGET)
	./$(TARGET)

# =========================
# Run GUI application
# =========================
rungui: $(GUI_TARGET)
	./$(GUI_TARGET)

# =========================
# Memory check with Valgrind
# =========================
val: $(TARGET) $(TEST_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

# Run valgrind only on unit tests (test runner)
.PHONY: val-test
val-test: $(TEST_TARGET)
	@echo "Running valgrind on unit tests ($(TEST_TARGET))"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_TARGET)

# =========================
# Setup / Clean
# =========================
setup:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

# =========================
# Install Dependencies
# =========================
dependencies:
	@echo "Installing FTXUI dependencies..."
	@echo "Checking for required packages..."
	@command -v cmake >/dev/null 2>&1 || { echo "cmake is required but not installed. Installing..."; sudo apt-get update && sudo apt-get install -y cmake; }
	@command -v g++ >/dev/null 2>&1 || { echo "g++ is required but not installed. Installing..."; sudo apt-get update && sudo apt-get install -y g++; }
	@echo "Checking if FTXUI is already built..."
	@if [ ! -d "$(FTXUI_INSTALL)/lib" ] || [ ! -f "$(FTXUI_INSTALL)/lib/libftxui-screen.a" ]; then \
		echo "FTXUI not found or incomplete. Building FTXUI..."; \
		if [ ! -d "ftxui_src" ]; then \
			echo "Cloning FTXUI repository..."; \
			git clone https://github.com/ArthurSonzogni/FTXUI.git ftxui_src; \
		fi; \
		mkdir -p ftxui_build; \
		cd ftxui_build && \
		cmake ../ftxui_src -DCMAKE_INSTALL_PREFIX=../$(FTXUI_INSTALL) && \
		make -j$(shell nproc) && \
		make install && \
		cd ..; \
		echo "FTXUI installed successfully!"; \
	else \
		echo "FTXUI is already installed."; \
	fi
	@echo "All dependencies are installed!"

# =========================
# Phony targets
# =========================
.PHONY: all clean test setup val install-deps rungui

.PHONY: run