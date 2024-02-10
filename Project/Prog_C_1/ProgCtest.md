```c

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display_list(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("La liste est vide.\n");
        return;
    }
    printf("Liste : ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void reset_list(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
    printf("Liste réinitialisée.\n");
}

void add_end(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        printf("Élément '%d' ajouté en fin de liste.\n", data);
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    printf("Élément '%d' ajouté en fin de liste.\n", data);
}

void remove_end(struct Node** head) {
    if (*head == NULL) {
        printf("Pas possible.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Élément supprimé de la fin de la liste.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    free(current);
    previous->next = NULL;
    printf("Élément supprimé de la fin de la liste.\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nBonjour, opération à effectuer :\n");
        printf("1 - Afficher\n");
        printf("2 - Réinitialiser\n");
        printf("3 - Ajouter un élément à la fin de la liste\n");
        printf("4 - Supprimer un élément à la fin de la liste\n");
        printf("5 - Quitter le programme\n");
        printf("Opération : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_list(head);
                break;
            case 2:
                reset_list(&head);
                break;
            case 3:
                printf("élément à ajouter : ");
                scanf("%d", &data);
                add_end(&head, data);
                break;
            case 4:
                remove_end(&head);
                break;
            case 5:
                printf("Fin du prog.\n");
                exit(0);
            default:
                printf("Choix invalide.\n");
        }
    }

    return 0;
}
```
