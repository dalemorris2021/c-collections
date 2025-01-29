#include <stdio.h>
#include <stdlib.h>

#include "array_list.h"
#include "linked_list.h"

void print_list(ArrayList *list, char *separator);

// void print_contains(ArrayList *list, int val);

int main(void) {
    char *separator = ", ";

    ArrayList *list = ArrayList_new();
    printf("Fresh list\n");

    print_list(list, separator);

    ArrayList_add(list, 4);
    printf("4 added\n");
    printf("size of list = %d\n", list->size);

    print_list(list, separator);

    ArrayList_add(list, 7);
    printf("7 added\n");
    printf("size of list = %d\n", list->size);

    print_list(list, separator);

    for (int i = 0; i < 9; i++) {
        ArrayList_add(list, i);
    }

    printf("size of list = %d\n", list->size);
    print_list(list, separator);

    /*LinkedList_addIndex(list, 1, 8);
    printf("8 inserted into position 2\n");
    printf("size of list = %d\n", list->size);

    print_list(list, separator);

    print_contains(list, 4);
    print_contains(list, 8);
    print_contains(list, 7);
    print_contains(list, 0);
    print_contains(list, -2);
    print_contains(list, 100);*/
}

void print_list(ArrayList *list, char *separator) {
    if (!list) {
        return;
    }

    if (!list->vals) {
        return;
    }

    printf("List: ");
    
    if (list->size >= 1) {
        printf("%d", list->vals[0]);
    }

    for (int i = 1; i < list->size; i++) {
        printf("%s%d", separator, list->vals[i]);
    }

    printf("\n");
}

/*
void print_contains(ArrayList *list, int val) {
    if (ArrayList_contains(list, val)) {
        printf("list contains %d\n", val);
    } else {
        printf("list does not contain %d\n", val);
    }
}
*/
