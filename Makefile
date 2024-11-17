# Compiler and flags
CC = gcc
CFLAGS = -Wall -lm

# Directories
BIN_DIR = bin
SRC_DIR = src
ADT_DIR = $(SRC_DIR)/ADT

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Mesinkarakter target
mesinkarakter: $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/mesinkarakter_test $(ADT_DIR)/mesinkarakter/mesinkarakter.c $(ADT_DIR)/mesinkarakter/driver_mesinkarakter.c