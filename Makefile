CC = clang
CFLAGS = -Wall -Wextra -g -std=c17

SRC_DIR = src
OBJ_DIR = build/obj
BIN_DIR = build/bin

TARGET = $(BIN_DIR)/chip8emu

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/*.c, $(OBJ_DIR)/*.o, $(SRC_FILES))

# Default make target
all: $(TARGET)

# Creating build directories
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

# Link binary
$(TARGET): $(OBJ_FILES) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
