#include <stdlib.h>

#include "array_list.h"

ArrayList *ArrayList_new(void) {
    ArrayList *list = malloc(sizeof(ArrayList));
    list->vals = malloc(10 * sizeof(int));
    list->size = 0;

    return list;
}

int ArrayList_isFull(ArrayList *list) {
    return list->size * sizeof(int) == sizeof(list->vals);
}

void ArrayList_expand(ArrayList *list) {
    int *newVals = malloc(2 * sizeof(list->vals));
    memcpy(newVals, list->vals, sizeof(list->vals));
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
