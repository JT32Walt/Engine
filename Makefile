# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra

# Linker flags for libraries
LDFLAGS := -Llibs -lSDL2

# Include directories
INCLUDES := -Iinclude -Iinclude/SDL -Iinclude/glm -Iinclude/glm/ext -Iinclude/glad -Iinclude/KHR

# Directories and target
SRC_DIR := src
BIN := my_program  # Desired name for the executable (no .exe here)

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*.cpp)


# Build the target
$(BIN).exe: $(SRCS)  # Ensure the target has .exe extension
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@ $(LDFLAGS)

# Clean up generated files
.PHONY: clean
clean:
	del /f *.exe
