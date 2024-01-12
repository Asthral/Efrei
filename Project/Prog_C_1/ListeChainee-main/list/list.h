/*
 * list.h
 *
 * Définition des structure de données pour la gestion de liste chainée
 */

#pragma once

typedef struct listchainee_st *listchainee_ptr;

struct listechainee_st {
  int N;
  listchainee_ptr next;
};

/* forward decl of functions */
void free_list(listchainee_ptr);
listchainee_ptr init_list(void);
listchainee_ptr reinit_list(listchainee_ptr);
listchainee_ptr load_list(char*);
void save_list(char*);
int test_elem_in_list(listchainee_ptr, int);
void append_list(listchainee_ptr, int);
void prepend_list(listchainee_ptr, int);
listchainee_ptr insert_elem_in_list(listchainee_ptr, int, int);
void delete_end_of_list(listchainee_ptr);
listchainee_ptr delete_start_of_list(listchainee_ptr);
listchainee_ptr delete_elem_in_list(listchainee_ptr, int);
