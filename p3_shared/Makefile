# Variables
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -Iinclude -MMD -MP
LDFLAGS := -lpthread  # Link pthread library
SRC_DIR := src
OBJ_DIR := obj
TARGET := hello

# Source and object files
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Dependency files
DEPS := $(OBJ:%.o=%.d)

# Default target
all: $(TARGET)

# Rule to link object files and create the executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

# Rule to compile .cpp files to .o files, also generating .d files for dependencies
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependency files, if they exist
-include $(DEPS)

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Phony targets
.PHONY: all clean
