#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "array_list.h"

ArrayList *ArrayList_new(void) {
    int32_t INITIAL_CAPACITY = 10;

    ArrayList *list = malloc(sizeof(ArrayList));
    list->vals = malloc(INITIAL_CAPACITY * sizeof(int32_t));
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;

    return list;
}

bool ArrayList_isFull(ArrayList *list) {
    return list->size == list->capacity;
}

void ArrayList_expand(ArrayList *list) {
    int32_t EXPANSION_FACTOR = 2;

    int32_t *newVals = malloc(EXPANSION_FACTOR * list->capacity * sizeof(int32_t));
    memcpy(newVals, list->vals, list->capacity * sizeof(int32_t));
    free(list->vals);
    list->vals = newVals;
    list->capacity *= 2;
}

void ArrayList_add(ArrayList *list, int32_t val) {
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

void ArrayList_addIndex(ArrayList *list, size_t index, int32_t val) {
    if (!list) {
        return;
    }

    if (!list->vals) {
        return;
    }

    if (index > (size_t)list->size) {
        return;
    }

    if (ArrayList_isFull(list)) {
        ArrayList_expand(list);
    }

    if (index == (size_t)list->size) {
        list->vals[list->size] = val;
        list->size++;
        return;
    }

    int32_t temp1 = list->vals[index];
    list->vals[index] = val;
    for (size_t i = index + 1; i < (size_t)list->size; i++) {
        int32_t temp2 = list->vals[i];
        list->vals[i] = temp1;
        temp1 = temp2;
    }
    list->vals[list->size] = temp1;

    list->size++;
}

void ArrayList_remove(ArrayList *list, int32_t val) {
    if (!list) {
        return;
    }

    if (!list->vals) {
        return;
    }

    if (list->size == 0) {
        return;
    }

    size_t index = 0;
    while (index < (size_t)list->size && list->vals[index] != val) {
        index++;
    }

    if (index == (size_t)list->size) {
        return;
    }

    for (size_t i = index; i < (size_t)list->size - 1; i++) {
        list->vals[i] = list->vals[i + 1];
    }

    list->size--;
}

void ArrayList_removeIndex(ArrayList *list, size_t index) {
    if (!list) {
        return;
    }

    if (!list->vals) {
        return;
    }

    if (list->size == 0) {
        return;
    }

    if (index >= (size_t)list->size) {
        return;
    }

    for (size_t i = index; i < (size_t)list->size - 1; i++) {
        list->vals[i] = list->vals[i + 1];
    }

    list->size--;
}

bool ArrayList_contains(ArrayList *list, int32_t val) {
    for (size_t i = 0; i < (size_t)list->size; i++) {
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
