# Compiler and flags
CC = gcc
CFLAGS = -Wall -lm

# Directories
BIN_DIR = bin
SRC_DIR = src
ADT_DIR = $(SRC_DIR)/ADT

# Ensure bin directory exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Target for mesinkarakter
mesinkarakter: $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/mesinkarakter_test $(ADT_DIR)/mesinkarakter/mesinkarakter.c $(ADT_DIR)/mesinkarakter/driver_mesinkarakter.c

# Target for mesinkata
mesinkata: $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/mesinkata_test $(ADT_DIR)/mesinkata/mesinkata.c $(ADT_DIR)/mesinkarakter/mesinkarakter.c $(ADT_DIR)/mesinkata/driver_mesinkata.c

# Target for arrayitems
arrayitems: $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/arrayitems_test $(ADT_DIR)/arrayitems/arrayitems.c $(ADT_DIR)/arrayitems/driver_arrayitems.c

# Target for queue
queue: $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/queue_test $(ADT_DIR)/queue/queue.c $(ADT_DIR)/mesinkata/mesinkata.c $(ADT_DIR)/mesinkarakter/mesinkarakter.c $(ADT_DIR)/queue/driver_queue.c

# Target for main program
main:
	$(CC) $(CFLAGS) -o main.exe $(SRC_DIR)/main.c $(SRC_DIR)/console.c \
	$(ADT_DIR)/arraydinamis/arraydin.c $(ADT_DIR)/arrayitems/arrayitems.c \
	$(ADT_DIR)/arrayuser/arrayuser.c $(ADT_DIR)/mesinkarakter/mesinkarakter.c \
	$(ADT_DIR)/mesinkata/mesinkata.c $(ADT_DIR)/queue/queue.c \
	$(ADT_DIR)/stack/stack.c $(SRC_DIR)/games/work/work.c \
	$(ADT_DIR)/setkeranjang/set.c $(ADT_DIR)/linkedlist/linkedlist.c \
	$(SRC_DIR)/wishlist/wishlist.c $(SRC_DIR)/cart/cart.c $(SRC_DIR)/art/art.c \
	$(SRC_DIR)/games/bioweapon/bioweapon.c $(SRC_DIR)/games/quantum_w0rdl3/quantum_w0rdl3.c \
	$(SRC_DIR)/games/tebakangka/tebakangka.c $(SRC_DIR)/games/w0rdl3/w0rdl3.c \
	$(SRC_DIR)/profile/profile.c $(SRC_DIR)/menu/menu_commands.c