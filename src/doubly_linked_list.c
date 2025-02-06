#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "doubly_linked_list.h"

DoublyLinkedList *DoublyLinkedList_create(void) {
    DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
    list->size = 0;
    return list;
}

void DoublyLinkedList_destroy(DoublyLinkedList *list) {
    if (!list) {
        return;
    }

    DoublyLinkedList_clear(list);
    free(list);
}

void DoublyLinkedList_addIndex(DoublyLinkedList *list, char *val, size_t index) {
    if (!list || index > (size_t) list->size) {
        return;
    }

    Node *newNode = malloc(sizeof(Node));
    newNode->val = val;
    if (list->size == 0) {
        list->head = newNode;
        list->tail = newNode;
        list->size++;
        return;
    }

    if (index == 0) {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
        list->size++;
        return;
    }

    if (index == (size_t) list->size) {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
        list->size++;
        return;
    }

    Node *currentNode = list->head;
    for (size_t i = 1; i < index; i++) {
        currentNode = currentNode->next;
    }

    newNode->next = currentNode->next;
    newNode->prev = currentNode;
    currentNode->next->prev = newNode;
    currentNode->next = newNode;
    list->size++;
}

void DoublyLinkedList_removeIndex(DoublyLinkedList *list, size_t index) {
    if (!list || list->size == 0 || index >= (size_t) list->size) {
        return;
    }

    if (list->size == 1) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return;
    }

    Node *temp;
    if (index == 0) {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        return;
    }

    if (index == (size_t) list->size - 1) {
        temp = list->tail;
        list->tail = list->tail->prev;
        free(temp);
        list->size--;
        return;
    }

    Node *currentNode = list->head;
    for (size_t i = 1; i <= index; i++) {
        currentNode = currentNode->next;
    }

    currentNode->prev->next = currentNode->next;
    currentNode->next->prev = currentNode->prev;
    free(currentNode);
    list->size--;
}

bool DoublyLinkedList_contains(DoublyLinkedList *list, char *val) {
    if (!list || list->size == 0) {
        return false;
    }
    
    Node *currentNode = list->head;
    for (size_t i = 0; i < (size_t) list->size; i++) {
        if (!strcmp(currentNode->val, val)) {
            return true;
        }

        currentNode = currentNode->next;
    }
    
    return false;
}

size_t DoublyLinkedList_indexOf(DoublyLinkedList *list, char *val) {
    if (!list || list->size == 0) {
        return -1;
    }
    
    Node *currentNode = list->head;
    for (size_t i = 0; i < (size_t) list->size; i++) {
        if (!strcmp(currentNode->val, val)) {
            return i;
        }

        currentNode = currentNode->next;
    }
    
    return -1;
}

void DoublyLinkedList_clear(DoublyLinkedList *list) {
    if (!list || list->size == 0) {
        return;
    }

    Node *currentNode = list->head;
    Node *temp;
    for (size_t i = 0; i < (size_t) list->size; i++) {
        free(currentNode->val);
        temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
