#include <stdbool.h>
#include <stdint.h>

#pragma once

typedef struct ArrayList {
    int32_t *vals;
    int32_t size;
    int32_t capacity;
} ArrayList;

ArrayList *ArrayList_new(void);

void ArrayList_add(ArrayList *list, int32_t val);

void ArrayList_addIndex(ArrayList *list, size_t index, int32_t val);

void ArrayList_remove(ArrayList *list, int32_t val);

void ArrayList_removeIndex(ArrayList *list, size_t index);

bool ArrayList_contains(ArrayList *list, int32_t val);

void ArrayList_clear(ArrayList *list);

void ArrayList_delete(ArrayList *list);
