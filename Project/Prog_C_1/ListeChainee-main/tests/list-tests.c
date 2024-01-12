/*
 * list-tests.c
 *
 * Unitary tests for list functions
 * These tests pre-condition, post-conditions and functional 
 */

#include "list.h"
#include <CUnit/Basic.h>

void
test_ix_in_list_with_list_null(void)
{
  CU_ASSERT(test_ix_in_list(NULL, 0) == 0);
  CU_ASSERT(test_ix_in_list(NULL, 1) == 0);
  CU_ASSERT(test_ix_in_list(NULL, 2) == 0);
  CU_ASSERT(test_ix_in_list(NULL, 3) == 0);
}

void
test_ix_in_list_with_list_with_ix(void)
{
  listchainee_ptr list = (listchainee_ptr)malloc(sizeof(struct listechainee_st));
  list->N = 1;
  list->next = NULL;
  CU_ASSERT(test_ix_in_list(list, 0) == 1);
}

void
test_ix_in_list_with_list_without_ix(void)
{
  listchainee_ptr list = (listchainee_ptr)malloc(sizeof(struct listechainee_st));
  list->N = 1;
  list->next = NULL;
  CU_ASSERT(test_ix_in_list(list, 1) == 0);  
}
