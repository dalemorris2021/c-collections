#include <stdlib.h>
#include <string.h>

#include "array_list.h"

ArrayList *ArrayList_new(void) {
    int INITIAL_CAPACITY = 10;

    ArrayList *list = malloc(sizeof(ArrayList));
    list->vals = malloc(INITIAL_CAPACITY * sizeof(int));
    list->size = 0;

    return list;
}

int ArrayList_isFull(ArrayList *list) {
    return list->size * sizeof(int) == sizeof(list->vals);
}

void ArrayList_expand(ArrayList *list) {
    int EXPANSION_FACTOR = 2;

    int *newVals = malloc(EXPANSION_FACTOR * sizeof(list->vals));
    memcpy(newVals, list->vals, list->size * sizeof(int));
    free(list->vals);
    list->vals = newVals;
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

void ArrayList_clear(ArrayList *list) {
    list->size = 0;
}

void ArrayList_delete(ArrayList *list) {
    free(list->vals);
    free(list);
}
