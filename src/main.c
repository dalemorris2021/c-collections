#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "doubly_linked_list.h"

char *strdup(const char *s);

void print_list(DoublyLinkedList *list, char *separator);

void print_contains(DoublyLinkedList *list, char *val);

void print_indexOf(DoublyLinkedList *list, char *val);

int32_t main(void) {
    char *separator = ", ";

    DoublyLinkedList *list = DoublyLinkedList_create();
    
    char *s1 = strdup("dog");
    char *s2 = strdup("frog");
    char *s3 = strdup("alligator");
    char *s4 = strdup("oven");
    char *s5 = strdup("of out");
    
    DoublyLinkedList_addIndex(list, s1, 0);
    DoublyLinkedList_addIndex(list, s2, 1);
    DoublyLinkedList_addIndex(list, s3, 2);
    DoublyLinkedList_addIndex(list, s4, 0);
    DoublyLinkedList_addIndex(list, s5, 2);

    print_list(list, separator); // oven, dog, of out, frog, alligator

    DoublyLinkedList_removeIndex(list, 4);
    DoublyLinkedList_removeIndex(list, 0);
    DoublyLinkedList_removeIndex(list, 1);

    print_list(list, separator); // dog, frog

    print_contains(list, "dog"); // contains
    print_contains(list, "oven"); // does not contain

    print_indexOf(list, "dog");
    print_indexOf(list, "frog");

    DoublyLinkedList_destroy(list);

    exit(EXIT_SUCCESS);
}

char *strdup(const char *s) {
    size_t size = strlen(s) + 1;
    char *p = malloc(size);
    if (p) {
        memcpy(p, s, size);
    }
    return p;
}

void print_list(DoublyLinkedList *list, char *separator) {
    if (!list || list->size == 0) {
        return;
    }

    printf("%s", list->head->val);

    if (!list->head->next) {
        printf("\n");
        return;
    }

    Node *currentNode = list->head->next;
    for (size_t i = 1; i < (size_t) list->size; i++) {
        printf("%s%s", separator, currentNode->val);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void print_contains(DoublyLinkedList *list, char *val) {
    if (DoublyLinkedList_contains(list, val)) {
        printf("list contains %s\n", val);
    } else {
        printf("list does not contain %s\n", val);
    }
}

void print_indexOf(DoublyLinkedList *list, char *val) {
    size_t index = DoublyLinkedList_indexOf(list, val);

    printf("Index of %s: %zu\n", val, index);
}
