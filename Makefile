SRC = src
INC = include
BUILD = build
OBJ = $(BUILD)/obj
BIN = $(BUILD)/bin

OBJS = $(OBJ)/main.o $(OBJ)/array_list.o $(OBJ)/doubly_linked_list.o $(OBJ)/linked_list.o

RM = rm -f
CC = clang
CFLAGS = -std=c99 -g -Wall -Wextra -Wpedantic -Werror
CPPFLAGS = -Iinclude

.PHONY: all run clean

all: dirs $(BIN)/main

dirs:
	mkdir -p $(INC) $(BUILD) $(OBJ) $(BIN)

$(BIN)/main: $(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(BIN)/main $(OBJS)

$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/array_list.o: $(SRC)/array_list.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $(OBJ)/array_list.o $(SRC)/array_list.c

$(OBJ)/doubly_linked_list.o: $(SRC)/doubly_linked_list.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $(OBJ)/doubly_linked_list.o $(SRC)/doubly_linked_list.c

$(OBJ)/linked_list.o: $(SRC)/linked_list.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $(OBJ)/linked_list.o $(SRC)/linked_list.c

run: dirs $(BIN)/main
	$(BIN)/main

clean:
	$(RM) $(OBJ)/*
	$(RM) $(BIN)/*
