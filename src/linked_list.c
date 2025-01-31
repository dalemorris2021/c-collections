#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "linked_list.h"

LinkedList *LinkedList_new(void) {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->size = 0;
    return list;
}

void LinkedList_add(LinkedList *list, int32_t val) {
    if (!list) {
        return;
    }

    if (!list->head) {
        list->head = malloc(sizeof(Node));
        list->head->val = val;
        list->size += 1;
        return;
    }

    Node *current = list->head;
    while (current->next) {
        current = current->next;
    }

    current->next = malloc(sizeof(Node));
    current->next->val = val;
    list->size += 1;
}

void LinkedList_addIndex(LinkedList *list, size_t index, int32_t val) {
    if (!list) {
        return;
    }

    if (index > (size_t)list->size) {
        return;
    }

    Node *newNode = malloc(sizeof(Node));
    newNode->val = val;
    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
        list->size += 1;
        return;
    }

    Node *current = list->head;
    for (size_t i = 0; i < index - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    list->size += 1;
}

void LinkedList_remove(LinkedList *list, int32_t val) {
    if (!list) {
        return;
    }

    if (!list->head) {
        return;
    }

    Node *oldNode;
    if (val == list->head->val) {
        oldNode = list->head;
        list->head = list->head->next;
        free(oldNode);
        list->size -= 1;
        return;
    }

    Node *current = list->head;
    while (current->next) {
        if (val == current->next->val) {
            oldNode = current->next;
            current->next = current->next->next;
            free(oldNode);
            list->size -= 1;
            break;
        }
    }
}

void LinkedList_removeIndex(LinkedList *list, size_t index) {
    if (!list) {
        return;
    }

    if (!list->head) {
        return;
    }

    if (index >= (size_t)list->size) {
        return;
    }

    Node *oldNode;
    if (index == 0) {
        oldNode = list->head;
        list->head = list->head->next;
        free(oldNode);
        list->size -= 1;
        return;
    }

    Node *current = list->head;
    for (size_t i = 0; i < index - 1; i++) {
        current = current->next;
    }
    oldNode = current->next;
    current->next = current->next->next;
    free(oldNode);
    list->size -= 1;
}

bool LinkedList_contains(LinkedList *list, int32_t val) {
    if (!list) {
        return 0;
    }

    if (!list->head) {
        return 0;
    }

    Node *current = list->head;
    while (current) {
        if (val == current->val) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

void LinkedList_clear(LinkedList *list) {
    if (!list) {
        return;
    }

    if (!list->head) {
        free(list);
        return;
    }

    Node *current = list->head;
    while (current->next) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    free(current);
}

void LinkedList_delete(LinkedList *list) {
    if (!list) {
        return;
    }

    LinkedList_clear(list);

    free(list);
}
