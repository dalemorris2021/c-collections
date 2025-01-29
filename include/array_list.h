#pragma once

typedef struct ArrayList {
    int *vals;
    int size;
    int capacity;
} ArrayList;

ArrayList *ArrayList_new(void);

void ArrayList_add(ArrayList *list, int val);

void ArrayList_addIndex(ArrayList *list, int pos, int val);

void ArrayList_remove(ArrayList *list, int val);

void ArrayList_removeIndex(ArrayList *list, int index);

int ArrayList_contains(ArrayList *list, int val);

void ArrayList_clear(ArrayList *list);

void ArrayList_delete(ArrayList *list);
