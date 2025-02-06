#include <stdint.h>

#pragma once

typedef struct Node {
    char *val;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct DoublyLinkedList {
    Node *head;
    Node *tail;
    int32_t size;
} DoublyLinkedList;

DoublyLinkedList *DoublyLinkedList_create(void);

void DoublyLinkedList_destroy(DoublyLinkedList *list);

void DoublyLinkedList_addIndex(DoublyLinkedList *list, char *val, size_t index);

void DoublyLinkedList_removeIndex(DoublyLinkedList *list, size_t index);

bool DoublyLinkedList_contains(DoublyLinkedList *list, char *val);

size_t DoublyLinkedList_indexOf(DoublyLinkedList *list, char *val);

void DoublyLinkedList_clear(DoublyLinkedList *list);
