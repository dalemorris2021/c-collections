#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_list.h"
#include "linked_list.h"

void print_list(ArrayList *list, char *separator);

void print_contains(ArrayList *list, int32_t val);

int32_t main(void) {
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

    ArrayList_addIndex(list, 0, 20);
    printf("20 added\n");
    printf("size of list = %d\n", list->size);

    print_list(list, separator);

    ArrayList_addIndex(list, 2, 40);
    printf("40 added\n");
    printf("size of list = %d\n", list->size);

    print_list(list, separator);

    ArrayList_addIndex(list, 4, 30);
    printf("30 added\n");
    printf("size of list = %d\n", list->size);

    print_list(list, separator);

    printf("capacity = %d\n", list->capacity);

    for (size_t i = 0; i < 6; i++) {
        ArrayList_add(list, i);
        print_list(list, separator);
    }

    printf("size of list = %d\n", list->size);
    print_list(list, separator);
    printf("capacity = %d\n", list->capacity);

    print_list(list, separator);

    print_contains(list, 4);
    print_contains(list, 8);
    print_contains(list, 7);
    print_contains(list, 0);
    print_contains(list, -2);
    print_contains(list, 100);

    ArrayList_remove(list, 4);

    printf("size of list = %d\n", list->size);
    print_list(list, separator);

    ArrayList_removeIndex(list, 3);
    print_list(list, separator);
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

    for (size_t i = 1; i < (size_t)list->size; i++) {
        printf("%s%d", separator, list->vals[i]);
    }

    printf("\n");
}

void print_contains(ArrayList *list, int32_t val) {
    if (ArrayList_contains(list, val)) {
        printf("list contains %d\n", val);
    } else {
        printf("list does not contain %d\n", val);
    }
}
