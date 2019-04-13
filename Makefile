# Our compiler
CC=gcc
# Folders
LIB_DIR=./lib/
INC_DIR=./include/
BIN_DIR=./bin/
SRC_DIR=./src/
TEST_DIR=./tests/
# Flags
CFLAGS=-I./lib/
DBFLAGS=-ggdb3 -O0 -g -Wall -Werror
RELEASEFLAGS=-O2
TESTFLAG=-D TEST
FLAGS=

TEST=$(wildcard $(TEST_DIR)*.c)
SRC=$(wildcard $(SRC_DIR)*.c)
OBJ=$(addprefix $(BIN_DIR),$(notdir $(SRC:.c=.o)))
TEST_OBJ=$(addprefix $(BIN_DIR),$(notdir $(TEST:.c=.o)))
EXE=./bin/main
TEST_EXE=./bin/tests

# Default we build release mode
all: release

# Release flags and stuff
release: FLAGS += $(RELEASEFLAGS)
release:
	@echo "Release Build"
release: executable

# Debug flags and stuff
debug: FLAGS += $(DBFLAGS)
debug:
	@echo "Debug Build"
debug: executable

# General main generator
executable: $(OBJ)
	@echo "Linking" $(EXE)
	@$(CC) -o $(EXE) $(OBJ)

# Compiles the .c into .o for the source
./bin/%.o: ./src/%.c
	@mkdir -p $(BIN_DIR)
	@echo "Compiling" $@ 
	@$(CC) -o $@ -c $< $(CFLAGS) $(FLAGS) $(TESTFLAG)

# To use when finishing the assignment
delivery: $(OBJ)
	@echo "Delivery Mode"
	@ar crs $(LIB_DIR)libcthread.a $(OBJ)

# Generate the test executable
tests: $(TEST_OBJ) $(OBJ)
	@echo "Linking Tests" $(TEST_EXE)
# Need to delete main.o to avoid multiple mains
	@$(CC) -o $(TEST_EXE) $(TEST_OBJ) $(OBJ)

# Compiles the .c into .o for the tests
./bin/%.o: ./tests/%.c
	@echo "Compiling Test" $@ 
	@mkdir -p $(BIN_DIR)
	@$(CC) -o $@ -c $< $(CFLAGS) $(FLAGS) $(TESTFLAG)

# Cleaning rule
clean:
	@echo "Cleaning"
	@rm -rf $(LIB_DIR)/*.a $(BIN_DIR)/*.o $(SRC_DIR)/*~ $(INC_DIR)/*~ *~