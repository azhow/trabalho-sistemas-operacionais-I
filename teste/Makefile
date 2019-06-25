# Our compiler
CC=gcc
# Folders
LIB_DIR=../lib/
INC_DIR=../include/
SRC_DIR=../src/
TEST_DIR=./
BIN_DIR=$(TEST_DIR)
# Flags
CFLAGS=-I$(LIB_DIR) -I$(INC_DIR)
DBFLAGS=-ggdb3 -O0 -g -Wall -Werror
RELEASEFLAGS=-O2
TESTFLAG=-D TEST
FLAGS=

TEST=$(wildcard $(TEST_DIR)*.c)
SRC=$(wildcard $(SRC_DIR)*.c)
OBJ=$(addprefix $(BIN_DIR),$(notdir $(SRC:.c=.o)))
TEST_OBJ=$(addprefix $(BIN_DIR),$(notdir $(TEST:.c=.o)))
EXE=../bin/main
TEST_EXE=./teste
# Default we build release mode
all: tests

# Compiles the .c into .o for the source
./%.o: ../src/%.c
	@mkdir -p $(BIN_DIR)
	@echo "Compiling" $@ 
	@$(CC) -o $@ -c $< $(CFLAGS) $(FLAGS)

# Manage the flags for the test mode
tests: FLAGS += $(DBFLAGS)
tests: FLAGS += $(TESTFLAG)
tests: OBJ += ../bin/support.o
tests: test_process
# Generate the test executable in debug mode
test_process: $(TEST_OBJ) $(OBJ)
	@echo "Linking Tests" $(TEST_EXE)
	@$(CC) -o $(TEST_EXE) $(TEST_OBJ) $(OBJ)

# Compiles the .c into .o for the tests
./%.o: ./%.c
	@echo "Compiling Test" $@ 
	@mkdir -p $(BIN_DIR)
	@$(CC) -o $@ -c $< $(CFLAGS) $(FLAGS)

# Cleaning rule
clean:
	@echo "Cleaning"
	@rm -rf $(LIB_DIR)/*.a $(BIN_DIR)/*.o $(SRC_DIR)/*~ $(INC_DIR)/*~ *~
	@rm $(TEST_EXE)