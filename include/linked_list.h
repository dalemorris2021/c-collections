#include <stdbool.h>
#include <stdint.h>

#pragma once

typedef struct Node {
    int32_t val;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    int32_t size;
} LinkedList;

LinkedList *LinkedList_new(void);

void LinkedList_add(LinkedList *list, int32_t val);

void LinkedList_addIndex(LinkedList *list, size_t index, int32_t val);

void LinkedList_remove(LinkedList *list, int32_t val);

void LinkedList_removeIndex(LinkedList *list, size_t index);

bool LinkedList_contains(LinkedList *list, int32_t val);

void LinkedList_clear(LinkedList *list);

void LinkedList_delete(LinkedList *list);
