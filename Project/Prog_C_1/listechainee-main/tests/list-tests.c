/*
 * list-tests.c
 *
 * Unitary tests for list functions
 * These tests pre-condition, post-conditions and functional 
 */

#include <stdlib.h>
#include <limits.h>
#include "list/list.h"
#include <CUnit/Basic.h>

/* List chainee courante */
extern listechainee_ptr curlist;


/*
 * Test for init_list
 */
void
test_init_list(void)
{
  /* Assert test conditions */
  init_list();
  CU_ASSERT((listechainee_ptr)NULL == curlist);
}

/*
 * Test for reinit_list
 */
void
test_reinit_list(void)
{
  /* Assert test conditions */
  listechainee_ptr list = (listechainee_ptr)malloc(sizeof(struct listechainee_st));
  CU_ASSERT(list != (listechainee_ptr)NULL);
  list->N = 1;
  list->next = (listechainee_ptr)NULL;
  CU_ASSERT(reinit_list(list) == curlist);
}

/*
 * Test for test_ix_in_list
 *
 * A test with list being NULL
 */
void
test_ix_in_list_with_list_null(void)
{
  /* Add ix 0 in null list is ok */
  CU_ASSERT(test_ix_in_list((listechainee_ptr)NULL, -1) == 0);
  CU_ASSERT(test_ix_in_list((listechainee_ptr)NULL, 0) == 1);
  CU_ASSERT(test_ix_in_list((listechainee_ptr)NULL, 1) == 0);
  CU_ASSERT(test_ix_in_list((listechainee_ptr)NULL, 2) == 0);
}

/*
 * Test for test_ix_in_list
 *
 * A test with list having one element only
 */
void
test_ix_in_list_with_list_with_ix(void)
{
  /* Allocate list for the test */
  listechainee_ptr list = (listechainee_ptr)malloc(sizeof(struct listechainee_st));
  CU_ASSERT(list != (listechainee_ptr)NULL);
  list->N = 1;
  list->next = (listechainee_ptr)NULL;
  /* Assert test conditions */
  CU_ASSERT(test_ix_in_list(list, -1) == 0);
  CU_ASSERT(test_ix_in_list(list, 0) == 1);
  CU_ASSERT(test_ix_in_list(list, 1) == 1);
  CU_ASSERT(test_ix_in_list(list, 2) == 0);
  /* Free list */
  free((void*)list);
}

/*
 * Test for test_ix_in_list
 *
 * A test with list having two elements
 */
void
test_ix_in_list_with_list_without_ix(void)
{
  /* Allocate list for the test */
  listechainee_ptr list = (listechainee_ptr)malloc(sizeof(struct listechainee_st));
  CU_ASSERT(list != (listechainee_ptr)NULL);
  list->N = 1;
  list->next = (listechainee_ptr)malloc(sizeof(struct listechainee_st));
  CU_ASSERT(list->next != (listechainee_ptr)NULL);
  list->next->N = 2;
  list->next->next = (listechainee_ptr)NULL;
  /* Assert test conditions */
  CU_ASSERT(test_ix_in_list(list, -1) == 0);  
  CU_ASSERT(test_ix_in_list(list, 0) == 1);  
  CU_ASSERT(test_ix_in_list(list, 1) == 1);  
  CU_ASSERT(test_ix_in_list(list, 2) == 1);  
  CU_ASSERT(test_ix_in_list(list, 3) == 0);
  /* Free list */
  free((void*)list->next);
  free((void*)list);
}

/*
 * Test for test_elem_in_list
 *
 * A test with list NULL
 */
void
test_elem_in_list_with_null_list(void)
{
  /* Asserting test conditions */
  CU_ASSERT(test_elem_in_list((listechainee_ptr)NULL,-1) == 0);
  CU_ASSERT(test_elem_in_list((listechainee_ptr)NULL, 0) == 0);
  CU_ASSERT(test_elem_in_list((listechainee_ptr)NULL, 1) == 0);
}

/*
 * Test for test_elem_in_list
 *
 * A test with list non NULL
 */
void
test_elem_in_list_with_non_null_list1(void)
{
  /* Allocate list for the test */
  listechainee_ptr list = (listechainee_ptr)malloc(sizeof(struct listechainee_st));
  CU_ASSERT(list != (listechainee_ptr)NULL);
  list->N = 1;
  list->next = (listechainee_ptr)malloc(sizeof(struct listechainee_st));
  CU_ASSERT(list->next != (listechainee_ptr)NULL);
  list->next->N = 2;
  list->next->next = (listechainee_ptr)NULL;
  /* Asserting test conditions */
  CU_ASSERT(test_elem_in_list(list,-1) == 0);
  CU_ASSERT(test_elem_in_list(list, 0) == 0);
  CU_ASSERT(test_elem_in_list(list, 1) == 1);
  CU_ASSERT(test_elem_in_list(list, 2) == 1);
  CU_ASSERT(test_elem_in_list(list, 3) == 0);
  /* Free memory */
  free((void*)list->next);
  free((void*)list);
}

/*
 * Test for test_elem_in_list
 *
 * A test with list non NULL and at int limit
 */
void
test_elem_in_list_with_non_null_list2(void)
{
  /* Allocate list for the test */
  listechainee_ptr list = (listechainee_ptr)malloc(sizeof(struct listechainee_st));
  CU_ASSERT(list != (listechainee_ptr)NULL);
  list->N = INT_MIN;
  list->next = (listechainee_ptr)malloc(sizeof(struct listechainee_st));
  CU_ASSERT(list->next != (listechainee_ptr)NULL);
  list->next->N = INT_MAX;
  list->next->next = (listechainee_ptr)NULL;
  /* Asserting test conditions */
  CU_ASSERT(test_elem_in_list(list, INT_MIN) == 1);
  CU_ASSERT(test_elem_in_list(list, INT_MIN+1) == 0);
  CU_ASSERT(test_elem_in_list(list, 0) == 0);
  CU_ASSERT(test_elem_in_list(list, 1) == 0);
  CU_ASSERT(test_elem_in_list(list, INT_MAX-1) == 0);
  CU_ASSERT(test_elem_in_list(list, INT_MAX) == 1);
  /* Free memory */
  free((void*)list->next);
  free((void*)list);
}

/*
 * Test for test_elem_in_list
 *
 * A test with list non NULL and at int limit
 */
void
test_elem_in_list_with_non_null_list3(void)
{
  /* Allocate list for the test */
  listechainee_ptr list = (listechainee_ptr)malloc(sizeof(struct listechainee_st));
  CU_ASSERT(list != (listechainee_ptr)NULL);
  list->N = INT_MIN+1;
  list->next = (listechainee_ptr)malloc(sizeof(struct listechainee_st));
  CU_ASSERT(list->next != (listechainee_ptr)NULL);
  list->next->N = INT_MAX-1;
  list->next->next = (listechainee_ptr)NULL;
  /* Asserting test conditions */
  CU_ASSERT(test_elem_in_list(list, INT_MIN) == 0);
  CU_ASSERT(test_elem_in_list(list, INT_MIN+1) == 1);
  CU_ASSERT(test_elem_in_list(list, 0) == 0);
  CU_ASSERT(test_elem_in_list(list, 1) == 0);
  CU_ASSERT(test_elem_in_list(list, INT_MAX-1) == 1);
  CU_ASSERT(test_elem_in_list(list, INT_MAX) == 0);
  /* Free memory */
  free((void*)list->next);
  free((void*)list);
}

/*
 * Test for append_list
 *
 * A test for appending element in list
 */
void
test_append_list_with_list_null(void)
{
  listechainee_ptr list = (listechainee_ptr)NULL;
  CU_ASSERT((list = append_list((listechainee_ptr)NULL, 0)) != NULL);
  /* First elem is 0 */
  CU_ASSERT(list->N == 0);
  CU_ASSERT(list->next == (listechainee_ptr)NULL);
  CU_ASSERT((list = append_list(list, 1)) != NULL);
  /* First elem is 1 */
  CU_ASSERT(list->next->N == 1);
  CU_ASSERT(list->next->next == (listechainee_ptr)NULL);
  /* Free memory */
  free_list(list);
}

/*
 * Test for append_list
 *
 * A test for appending element in non null list
 */
void
test_append_list_with_list_non_null(void)
{
  listechainee_ptr list = (listechainee_ptr)malloc(sizeof(struct listechainee_st));
  list->N = 0;
  list->next = (listechainee_ptr)NULL;
  CU_ASSERT((list = append_list(list, 1)) != NULL);
  /* Second elem is 1 */
  CU_ASSERT(list->next->N == 1);
  CU_ASSERT(list->next->next == (listechainee_ptr)NULL);
  CU_ASSERT(append_list(list, 1) == NULL);
  /* Second elem is 1 */
  CU_ASSERT(list->next->N == 1);
  CU_ASSERT(list->next->next == (listechainee_ptr)NULL);
  CU_ASSERT(append_list(list, 2) != NULL);
  /* Thirst elem is 2 */
  CU_ASSERT(list->next->next->N == 2);
  CU_ASSERT(list->next->next->next == (listechainee_ptr)NULL);
  /* free memory */
  free_list(list);
}

/*
 * Test for prepend_list
 *
 * A test for prepending element in list
 */
void
test_prepend_list_with_list_null(void)
{
  listechainee_ptr list = (listechainee_ptr)NULL;
  CU_ASSERT((list = prepend_list(list, 0)) != NULL);
  /* Second elem is 1 */
  CU_ASSERT(list->N == 0);
  CU_ASSERT(list->next == (listechainee_ptr)NULL);
  CU_ASSERT((list = prepend_list(list, 1)) != NULL);
  /* First elem is 1 */
  CU_ASSERT(list->N == 1);
  /* Second elem is 0 */
  CU_ASSERT(list->next->N == 0);
  CU_ASSERT(list->next->next == (listechainee_ptr)NULL);
  /* free memory */
  free_list(list);
}

/*
 * Test for prepend_list
 *
 * A test for prepending element in non null list
 */
void
test_prepend_list_with_list_non_null(void)
{
  listechainee_ptr list = (listechainee_ptr)malloc(sizeof(struct listechainee_st));
  list->N = 0;
  list->next = (listechainee_ptr)NULL;
  /* Prepend 1 */
  CU_ASSERT((list = prepend_list(list, 1)) != NULL);
  /* First elem is 1 */
  CU_ASSERT(list->N == 1);
  /* Second elem is 0 */
  CU_ASSERT(list->next->N == 0);
  CU_ASSERT(list->next->next == (listechainee_ptr)NULL);
  CU_ASSERT(prepend_list(list, 1) == NULL);
  /* First elem is 1 */
  CU_ASSERT(list->N == 1);
  /* Second elem is 0 */
  CU_ASSERT(list->next->N == 0);
  CU_ASSERT(list->next->next == (listechainee_ptr)NULL);
  CU_ASSERT((list = prepend_list(list, 2)) != NULL);
  /* First elem is 2 */
  CU_ASSERT(list->N == 2);
  /* Second elem is 1 */
  CU_ASSERT(list->next->N == 1);
  /* Third & last elem is 0 */
  CU_ASSERT(list->next->next->N == 0);
  CU_ASSERT(list->next->next->next == (listechainee_ptr)NULL);
  /* free memory */
  free_list(list);
}
