# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -o2 -fPIC -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
TEST_DIR = tests
TEST_BIN_DIR = test_bin

# File extensions
SRC_EXT = .cpp
OBJ.EXT = .o
LIB_EXT = .so

# Library name
LIB_NAME = linalg

# Sources and objects
SRC_FILES = $(wildcard $(SRC_DIR)/*$(SRC_EXT))
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%$(SRC_EXT)=$(OBJ_DIR)/%$(OBJ_EXT))

# Test files and test executables
TEST_FILES = $(wildcard $(TEST_DIR)/*$(SRC_EXT))
TEST_BINS = $(TEST_FILES:$(TEST_DIR)/%$(SRC_EXT)=$(TEST_BIN_DIR)/%)

# Targets
all: $(LIB_DIR)/$(LIB_NAME)$(LIB_EXT)

# Build dynamic library
$(LIB_DIR)/$(LIB_NAME)$(LIB_EXT): $(OBJ_FILES)
	$(CXX) -shared -o $@ $^

# Compile source files into object files
$(OBJ_DIR)/%$(OBJ_EXT): $(SRC_DIR)/%$(SRC_EXT)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test files
make_test: $(TEST_BINS)
$(TEST_BIN_DIR)/%: $(TEST_DIR)/%$(SRC_EXT) $(LIB_DIR)/$(LIB_NAME)$(LIB_EXT)
	$(CXX) $(CXXFLAGS) $< -o $@ $(LIB_DIR)/$(LIB_NAME)$(LIB_EXT) -Wl,-rpath=$(LIB_DIR)

# Clean object files, libraries, and executables
clean:
	rm -rf $(OBJ_DIR)/* $(LIB_DIR)/*

# Clean object files, libraries, and executables
clean_test:
	rm -rf $(TEST_BIN_DIR)/*

# Run tests
run_test: $(TEST_BINS)
	@for test in $(TEST_BINS); do \
		$$test; \
	done

.PHONY: all clean make_test clean_test run_test
