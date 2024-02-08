#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "list.h"


struct element * createlist (int val) {
    struct element *newlist = malloc(sizeof(struct element));
    newlist -> value = val;
    newlist -> pointer = NULL;
    return newlist;
}

bool listisempty (struct element *list) {
    return list == NULL;
}

int lenlist (struct element *list) {
    int len = 0;
    while (!listisempty(list)) {
        list = list -> pointer;
        len += 1;
    }
    return len;
}

void printlist(struct element *list) {
    printf("--- MY LIST ---\n");
    while (!listisempty(list)) {
        printf("%d\n", list -> value);
        list = list -> pointer;
    }
    printf("--- END ---\n");
}

void debuglist(struct element *list) {
    int i = 0;
    printf("--- DEBUGGING LIST ---\n");
    printf("--- LEN LIST --\n");
    printf("%d\n", lenlist(list));
    while (!listisempty(list)) {
        printf("--- INDEX %d ---\n", i);
        printf("Value : %d\n", list -> value);
        if (!(list -> pointer == NULL)) {
            printf("Pointing on : %d\n", list -> pointer -> value);
        }
        i += 1;
        list = list -> pointer;
    }
}

struct element * indexlist(struct element *list, int idx) {
    assert(idx >= 0 && idx < lenlist(list));
    for (int i = 0; i < idx; i++) {
        list = list -> pointer;
    }
    return list;
}

void prependlist(struct element *list, int val) {
    struct element *newlist = malloc(sizeof(struct element));
    newlist -> value = list -> value;
    newlist -> pointer = list -> pointer;
    list -> value = val;
    list -> pointer = newlist;

}

void appendlist(struct element *list, int val) {
    struct element *newlist = malloc(sizeof(struct element));
    newlist -> value = val;
    newlist -> pointer = NULL;
    indexlist(list, lenlist(list) - 1) -> pointer = newlist;
}

void deletefirst(struct element *list) {
    int tmpvalue = indexlist(list, 1) -> value;
    struct element *tmpptr = indexlist(list, 1) -> pointer;
    free(indexlist(list, 1));
    list -> value = tmpvalue;
    list -> pointer = tmpptr;
}

void deletelast(struct element *list) {
    int len = lenlist(list);
    struct element *tmpptr = indexlist(list, len - 1);
    indexlist(list, len - 2) -> pointer = NULL;
    free(tmpptr);
}

void addelement(struct element *list, int idx, int val) {
    if (idx == 0) {
        prependlist(list, val);
    }
    else if (idx > 0 && idx < (lenlist(list) - 1)) {
        struct element *newelement = malloc(sizeof(struct element));
        newelement -> value = val;
        newelement -> pointer = indexlist(list, idx);
        indexlist(list, idx - 1) -> pointer = newelement;
    }
    else if (idx == (lenlist(list) - 1)) {
        appendlist(list, val);
    }
    else {
        assert(1 != 1);
    }
}

void removeelement(struct element *list, int idx) {
    if (idx == 0) {
        deletefirst(list);
    }
    else if (idx > 0 && idx < (lenlist(list) - 1)) {
        struct element *tmpptr = indexlist(list, idx - 1);
        struct element *tmpptr2 = tmpptr -> pointer;
        tmpptr -> pointer = tmpptr2 -> pointer;
        free(tmpptr2);
    }
    else if (idx == (lenlist(list) - 1)) {
        deletelast(list);
    }
    else {
        assert(1 != 1);
    }
}