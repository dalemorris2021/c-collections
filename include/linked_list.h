#pragma once

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    int size;
} LinkedList;

LinkedList *LinkedList_new(void);

void LinkedList_add(LinkedList *list, int val);

void LinkedList_addIndex(LinkedList *list, int pos, int val);

void LinkedList_remove(LinkedList *list, int val);

void LinkedList_removeIndex(LinkedList *list, int index);

int LinkedList_contains(LinkedList *list, int val);

void LinkedList_clear(LinkedList *list);

void LinkedList_delete(LinkedList *list);
