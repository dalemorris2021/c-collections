#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_list.h"

ArrayList *ArrayList_new(void) {
    int INITIAL_CAPACITY = 10;

    ArrayList *list = malloc(sizeof(ArrayList));
    list->vals = malloc(INITIAL_CAPACITY * sizeof(int));
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;

    return list;
}

int ArrayList_isFull(ArrayList *list) {
    return list->size == list->capacity;
}

void ArrayList_expand(ArrayList *list) {
    int EXPANSION_FACTOR = 2;

    int *newVals = malloc(EXPANSION_FACTOR * list->capacity * sizeof(int));
    memcpy(newVals, list->vals, list->capacity * sizeof(int));
    free(list->vals);
    list->vals = newVals;
    list->capacity *= 2;
}

void ArrayList_add(ArrayList *list, int val) {
    if (!list) {
        return;
    }

    if (!list->vals) {
        return;
    }

    if (ArrayList_isFull(list)) {
        ArrayList_expand(list);
    }

    list->vals[list->size] = val;
    list->size++;
}

void ArrayList_addIndex(ArrayList *list, int index, int val) {
    if (!list) {
        return;
    }

    if (!list->vals) {
        return;
    }

    if (index < 0 || index > list->size) {
        return;
    }

    if (ArrayList_isFull(list)) {
        ArrayList_expand(list);
    }

    if (index == list->size) {
        list->vals[list->size] = val;
        list->size++;
        return;
    }

    int temp1 = list->vals[index];
    list->vals[index] = val;
    for (int i = index + 1; i < list->size; i++) {
        int temp2 = list->vals[i];
        list->vals[i] = temp1;
        temp1 = temp2;
    }
    list->vals[list->size] = temp1;

    list->size++;
}

void ArrayList_remove(ArrayList *list, int val) {
    if (!list) {
        return;
    }

    if (!list->vals) {
        return;
    }

    if (list->size == 0) {
        return;
    }

    int index = 0;
    while (index < list->size && list->vals[index] != val) {
        index++;
    }

    if (index == list->size) {
        return;
    }

    for (int i = index; i < list->size - 1; i++) {
        list->vals[i] = list->vals[i + 1];
    }

    list->size--;
}

void ArrayList_removeIndex(ArrayList *list, int index) {
    if (!list) {
        return;
    }

    if (!list->vals) {
        return;
    }

    if (list->size == 0) {
        return;
    }

    if (index < 0 || index >= list->size) {
        return;
    }

    for (int i = index; i < list->size - 1; i++) {
        list->vals[i] = list->vals[i + 1];
    }

    list->size--;
}

int ArrayList_contains(ArrayList *list, int val) {
    for (int i = 0; i < list->size; i++) {
        if (val == list->vals[i]) {
            return 1;
        }
    }

    return 0;
}

void ArrayList_clear(ArrayList *list) {
    list->size = 0;
}

void ArrayList_delete(ArrayList *list) {
    free(list->vals);
    free(list);
}
