# Makefile for compiling and building the main program

# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra

# Source directories
SRC_DIR := /home/jy/hm_dnn/src
SRC_DIR_P := /home/jy/hm_dnn/src/Policy
# Add DIR_M, DIR_P, ...

# Output directory
BUILD_DIR := /home/jy/A/build

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR_P)/*.c)

# Object files
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)

# Include directories
INCLUDES := -I$(SRC_DIR) -I$(SRC_DIR_P)

# Output binary name
OUTPUT := hmdnn

# Rule to build the binary
$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(OUTPUT)

# Rule to compile .c files to .o
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Phony target to clean the build directory
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(OUTPUT)