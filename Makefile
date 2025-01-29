SRC = src
INC = include
BUILD = build
OBJ = $(BUILD)/obj
BIN = $(BUILD)/bin

OBJS = $(OBJ)/main.o $(OBJ)/linked_list.o $(OBJ)/array_list.o

RM = rm -f
CC = clang
CFLAGS = -std=c99 -g -Wall
CPPFLAGS = -Iinclude

.PHONY: all
all: dirs $(BIN)/main

dirs:
	mkdir -p $(INC) $(OBJ) $(BIN)

$(BIN)/main: $(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(BIN)/main $(OBJS)

$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/linked_list.o: $(SRC)/linked_list.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $(OBJ)/linked_list.o $(SRC)/linked_list.c

$(OBJ)/array_list.o: $(SRC)/array_list.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $(OBJ)/array_list.o $(SRC)/array_list.c

.PHONY: run
run: $(BIN)/main
	$(BIN)/main

.PHONY: clean
clean:
	$(RM) $(OBJ)/*
	$(RM) $(BIN)/*
