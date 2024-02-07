/*
 * test-main.c
 *
 * main routine for tests
 */

#include <stdio.h>
#include <CUnit/Basic.h>

#include "list/list.h"
#include "list-tests.h"			// Include tests decl for list library
#include "cmd-tests.h"			// Include tests decl for command line behaviour

/* List chainee courante */
listechainee_ptr curlist = (listechainee_ptr)NULL;

/*
 * Forward decl for our functions
 */
int main(int, char**);
int init_suite_tests4list(void);
int clean_suite_tests4list(void);
int init_suite_tests4cmd(void);
int clean_suite_tests4cmd(void);


/*
 * ==============================================================================
 *                                            Suite for testing the list library
 *
 */

/* The suite initialization function.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite_tests4list(void)
{
  return 0;
}

/* The suite cleanup function.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite_tests4list(void)
{
  return 0;
}

/*
 * ==============================================================================
 *                                        Suite for testing the command behavior
 *
 */

/* The suite initialization function.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite_tests4cmd(void)
{
  return 0;
}

/* The suite cleanup function.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite_tests4cmd(void)
{
  return 0;
}

/*
 * ==============================================================================
 *                                                                Main for tests
 *
 */

/*
 * main
 *
 * The main function for the tests entry point. It creates tghe tests suites,
 * provision the tests for each test suite and finally executes all tests.
 */
int
main(int argc, char** argv)
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite for testing the list library to the registry */
   pSuite = CU_add_suite("Suite_4_list", init_suite_tests4list, clean_suite_tests4list);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* 6 tests */
   if ((NULL == CU_add_test(pSuite, "test of test_init_list", 
                            test_init_list)) ||
       (NULL == CU_add_test(pSuite, "test of test_reinit_list", 
                            test_reinit_list)) ||
       (NULL == CU_add_test(pSuite, "test of test_ix_in_list with null list", 
                            test_ix_in_list_with_list_null)) ||
       (NULL == CU_add_test(pSuite, "test of test_ix_in_list with list with ix", 
                            test_ix_in_list_with_list_with_ix)) ||
       (NULL == CU_add_test(pSuite, "test of test_ix_in_list with list without ix", 
                            test_ix_in_list_with_list_without_ix)) ||
       (NULL == CU_add_test(pSuite, "test of test_elem_in_list with null list", 
                            test_elem_in_list_with_null_list)) ||
       (NULL == CU_add_test(pSuite, "test of test_elem_in_list with non null list", 
                            test_elem_in_list_with_non_null_list1)) ||
       (NULL == CU_add_test(pSuite, "test of test_elem_in_list with non null list (int limit)", 
                            test_elem_in_list_with_non_null_list2)) ||
       (NULL == CU_add_test(pSuite, "test of test_elem_in_list with non null list (int limit) #2", 
                            test_elem_in_list_with_non_null_list3)) ||
       (NULL == CU_add_test(pSuite, "test of test_append_list_with_list_null", 
                            test_append_list_with_list_null)) ||
       (NULL == CU_add_test(pSuite, "test of test_append_list_with_list_non_null", 
                            test_append_list_with_list_non_null)) ||
       (NULL == CU_add_test(pSuite, "test of test_prepend_list_with_list_null", 
                            test_prepend_list_with_list_null)) ||
       (NULL == CU_add_test(pSuite, "test of test_prepend_list_with_list_non_null", 
                            test_prepend_list_with_list_non_null))
       )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add a suite to the registry */
   /* 1 test */
   pSuite = CU_add_suite("Suite_4_command", init_suite_tests4cmd, clean_suite_tests4cmd);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests for the command to the suite */
   if ((NULL == CU_add_test(pSuite, "test of basic command launch ",
                            test_command_basic_invocation_0)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (-v)",
                            test_command_basic_invocation_v)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (-v -h)",
                            test_command_basic_invocation_vh)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (--verbose)", 
                            test_command_basic_invocation_verbose)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (--verbose --help)", 
                            test_command_basic_invocation_verbose_help)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (-A 1 -d)", 
                            test_command_basic_invocation_A1d)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (-P 2 -d)", 
                            test_command_basic_invocation_P2d)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (--append 3 --display)", 
                            test_command_basic_invocation_append_3_display)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (--prepend 4 --display)", 
                            test_command_basic_invocation_prepend_4_display)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (-A 1 -P 2 -d)", 
                            test_command_basic_invocation_A1P2d)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (--append 1 --prepend 2 --display)", 
                            test_command_basic_invocation_append_1_prepend_2_display)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (-v -A 1 -d)", 
                            test_command_basic_invocation_vA1d)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (-v -P 2 -d)", 
                            test_command_basic_invocation_vP2d)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (--verbose --append 3 --display)", 
                            test_command_basic_invocation_verbose_append_3_display)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (--verbose --prepend 4 --display)", 
                            test_command_basic_invocation_verbose_prepend_4_display)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (-v -A 1 -P 2 -d)", 
                            test_command_basic_invocation_vA1P2d)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (--verbose --append 1 --prepend 2 --display)", 
                            test_command_basic_invocation_verbose_append_1_prepend_2_display)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (-v -A 1 -P 2 -d -s testlist1.l)", 
                            test_command_basic_invocation_vA1P2ds_testlist1_l)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (--verbose --append 1 --prepend 2 --display --save testlist1.l)", 
                            test_command_basic_invocation_verbose_append_1_prepend_2_display_save_testlist1_l)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (-v -l testlist1.l -d)", 
                            test_command_basic_invocation_vl_testlist1_l_d)) ||
       (NULL == CU_add_test(pSuite, "test of basic command launch (--verbose --load testlist1.l --display)", 
                            test_command_basic_invocation_verbose_load_testlist1_l_display))
       )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
   
   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();  
}
