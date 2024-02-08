#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "src/list.h"

int main (void) {
    struct element *testlist = createlist(8);

    printlist(testlist); //DOIT AFFICHER [8]

    //false => affiche 0
    //true => affiche 1
    
    printf("testlist est vide ? %d\n", listisempty(testlist)); //DOIT AFFICHER 0
    printf("NULL est vide ? %d\n", listisempty(NULL)); //DOIT AFFICHER 1

    printf("Len de testlist = %d\n", lenlist(testlist)); //DOIT AFFICHER 1
    printf("Len de NULL = %d\n", lenlist(NULL)); //DOIT AFFICHER 0

    printf("testlist[0] = %d\n", indexlist(testlist, 0) -> value); //DOIT AFFICHER 8

    printlist(testlist); //DOIT AFFICHER [8]

    printf("-> ajout debut liste 3\n");

    prependlist(testlist, 3);

    printlist(testlist); //DOIT AFFICHER [3, 8]

    printf("-> ajout fin liste 7\n");
    printf("-> ajout fin liste 45\n");
    
    appendlist(testlist, 7);
    appendlist(testlist, 45);

    printlist(testlist); //DOIT AFFICHER [3, 8, 7, 45]

    printf("-> ajout index 2 valeur 9\n");

    addelement(testlist, 2, 9);

    printlist(testlist); //DOIT AFFICHER [3, 8, 9, 7, 45]

    printf("-> enleve premier element\n");

    deletefirst(testlist);

    printlist(testlist); //DOIT AFFICHER [8, 9, 7, 45]

    printf("-> enleve dernier element\n");

    deletelast(testlist);

    printlist(testlist); //DOIT AFFICHER [8, 9, 7]

    printf("-> enleve element index 1\n");

    removeelement(testlist, 1);

    printlist(testlist); //DOIT AFFICHER [8, 7]

    return 0;
}
