#include <stdbool.h>

struct element {
    int value;
    struct element *pointer;
};

// idx = index, val = value

//creer une liste d'un element ayant pour valeur "val"
struct element * createlist(int val);

//test si une liste est vide ou nom, renvoie un bool
bool listisempty(struct element *list);

//renvoie le nombre d'elements d'une liste
int lenlist(struct element *list);

//affiche le contenu de la liste
void printlist (struct element *list);

//affiche le contenu de la liste de maniere plus detaillee
void debuglist(struct element *list);

//renvoie l'element aynt pour index "idx"
struct element * indexlist(struct element *list, int idx);

//ajoute au debut de la liste un element de valeur "val"
void prependlist(struct element *list, int val);

//ajoute a la fin de la liste un element de valeur "val"
void appendlist(struct element *list, int val);

//supprime le premier element de la liste
void deletefirst(struct element *list);

//supprime le dernier element de la liste
void deletelast(struct element *list);

//ajoute un element de valeur "val" ayant pour index "idx"
void addelement(struct element *list, int idx, int val);

//supprim l'element ayant pour index "idx"
void removeelement(struct element *list, int idx);