/*
 * list.h
 *
 * Définition des structure de données pour la gestion de liste chainée
 */

#pragma once

typedef struct listechainee_st *listechainee_ptr;

struct listechainee_st {
  int N;
  listechainee_ptr next;
};

/* forward decl of functions */
void free_list(listechainee_ptr);
void init_list(void);
void display_list(listechainee_ptr);
listechainee_ptr reinit_list(listechainee_ptr);
listechainee_ptr load_list(char*);
listechainee_ptr save_list(listechainee_ptr, char*);
int test_elem_in_list(listechainee_ptr, int);
int test_ix_in_list(listechainee_ptr, int);
listechainee_ptr append_list(listechainee_ptr, int);
listechainee_ptr prepend_list(listechainee_ptr, int);
listechainee_ptr insert_elem_in_list(listechainee_ptr, int, int);
void delete_end_of_list(listechainee_ptr);
listechainee_ptr delete_start_of_list(listechainee_ptr);
listechainee_ptr delete_elem_in_list(listechainee_ptr, int);
