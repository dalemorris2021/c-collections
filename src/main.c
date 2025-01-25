#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

void print_list(LinkedList *list, char *separator);

void print_contains(LinkedList *list, int val);

int main(void) {
    char *separator = ", ";

    LinkedList *list = LinkedList_new();
    printf("Fresh list\n");

    LinkedList_add(list, 4);
    printf("4 added\n");
    printf("size of list = %d\n", list->size);

    LinkedList_add(list, 7);
    printf("7 added\n");
    printf("size of list = %d\n", list->size);

    LinkedList_addIndex(list, 1, 8);
    printf("8 inserted into position 2\n");
    printf("size of list = %d\n", list->size);

    print_list(list, separator);

    print_contains(list, 4);
    print_contains(list, 8);
    print_contains(list, 7);
    print_contains(list, 0);
    print_contains(list, -2);
    print_contains(list, 100);
}

void print_list(LinkedList *list, char *separator) {
    if (!list) {
        return;
    }

    if (!list->head) {
        return;
    }

    Node *current = list->head;
    printf("%d", current->val);
    while (current->next) {
        current = current->next;
        printf("%s%d", separator, current->val);
    }
    printf("\n");
}

void print_contains(LinkedList *list, int val) {
    if (LinkedList_contains(list, val)) {
        printf("list contains %d\n", val);
    } else {
        printf("list does not contain %d\n", val);
    }
}
