# =========================
# Project Configuration
# =========================
MAKEFLAGS += -j4 #add numeber to the j to limit the number of cores e.g. -j4
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude -Isrc
BUILD_DIR := build
SRC_DIR := src
TEST_DIR := testing

# =========================
# Targets
# =========================
TARGET := $(BUILD_DIR)/main
TEST_TARGET := $(BUILD_DIR)/test_runner

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

CORE_OBJS := $(filter-out $(BUILD_DIR)/main.o,$(OBJS))

TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS := $(TEST_SRCS:$(TEST_DIR)/%.cpp=$(BUILD_DIR)/%.test.o)

# Demo program (kept outside src/ so it won't be picked up by the src/*.cpp wildcard)
DEMO_SRC := demos/demo.cpp
DEMO_OBJ := $(BUILD_DIR)/demo_demo.o

# =========================
# Default target
# =========================
all: setup $(TARGET)

# =========================
# Build main project
# =========================
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

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
# Run main binary
# =========================
run: $(TARGET)
	./$(TARGET)

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
# Phony targets
# =========================
.PHONY: all clean test setup val

.PHONY: run