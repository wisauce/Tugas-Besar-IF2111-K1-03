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

mesinkata: $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/mesinkata_test $(ADT_DIR)/mesinkata/mesinkata.c $(ADT_DIR)/mesinkarakter/mesinkarakter.c $(ADT_DIR)/mesinkata/driver_mesinkata.c

arrayitems: $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/arrayitems_test $(ADT_DIR)/arrayitems/arrayitems.c $(ADT_DIR)/arrayitems/driver_arrayitems.c

queue: $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/queue_test $(ADT_DIR)/queue/queue.c $(ADT_DIR)/mesinkata/mesinkata.c $(ADT_DIR)/mesinkarakter/mesinkarakter.c $(ADT_DIR)/queue/driver_queue.c

main: 
	$(CC) $(CFLAGS) -o main.exe $(SRC_DIR)/main.c $(SRC_DIR)/console.c \
	$(ADT_DIR)/arraydinamis/arraydin.c $(ADT_DIR)/arrayitems/arrayitems.c \
	$(ADT_DIR)/arrayuser/arrayuser.c $(ADT_DIR)/mesinkarakter/mesinkarakter.c \
	$(ADT_DIR)/mesinkata/mesinkata.c
