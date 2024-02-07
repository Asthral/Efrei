/*
 * cmd-tests.c
 *
 * Unitary tests for command behaviour
 * These tests test pre-condition, post-conditions and functional 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <CUnit/Basic.h>

#include "list/list.h"

#define NB_TESTS 				22
#define BUFFER_MAX_SIZE 		10240
#define ERROR_BUFFER_SIZE		1024
#define LIST_BUFFER_SIZE		1024
#define DEBUG_COMMAND_STRING 	"./Debug/listechainee"
#define RELEASE_COMMAND_STRING 	"./Release/listechainee"

/* Buffer used for reading the command output */
char buf[BUFFER_MAX_SIZE];

/* */

/*
 * popen_listechainee
 *
 * Open a pipe for reading from launched command listechainee
 */
FILE *
popen_listechainee(char* args)
{
  /* Compute the size of the string to allocate for command */
  char *cmd = (char*)malloc(strlen("./Debug/listechainee") + strlen(args) + 2);
  /* Format the command  */
  sprintf(cmd, DEBUG_COMMAND_STRING " %s", args);
  /* Open the pipe for launching the command with a shell: 'sh -c "<command>"' */
  /* The returned file pointer will allow us to read ("r") the command standard output/error  */
  FILE *fp = popen(cmd, "r");
  /* Free the command string allocated */
  free((void*)cmd);
  /* Return the file pointer */
  return fp;
}

/*
 * These are the expected results as strings
 */
char* results[NB_TESTS] = {
  /* ===================================================================================================================== 0 = */
  /*  == $ lisetchainee                                                                                                      = */
  "listechainee: error: no option was specified!\n"
  "listechainee: usage: listechainee [-hvdxXqNi] [-l|-s <filename>] [-t|-A|-P <elem>] [-I|-r <elem,[+]pos>]                     \n"
  "                                 Options:                                                                                    \n"
  "                                 Options:                                                                                    \n"
  "                                    [-h|--help]                  display this help message                                   \n"
  "                                    [-v|--verbose]               increase verbosity                                          \n"
  "                                 Commands:                                                                                   \n"
  "                                    [-i|--init]                  init a linked list                                          \n"
  "                                    [-l|--load <filename>]       load a linked list from a file <filename>                   \n"
  "                                    [-s|--save <filename>]       save a linked list in a file <filename>                     \n"
  "                                    [-t|--test <elem>]           test if an element <elem> is contained in the list          \n"
  "                                    [-A|--append <elem>]         append the element <elem> in the list                       \n"
  "                                    [-P|--prepend <elem>]        prepend the element <elem> in the list                      \n"
  "                                    [-I|--insert <elem,[+]pos>]  insert the element <elem> in the list at position <pos>.    \n"
  "                                                                 <pos> is the index of the element at which the insertion    \n"
  "                                                                 will occcur after, if <pos> starts with '+'. Otherwise <pos>\n"
  "                                                                 is the value of the element after which the insertion will  \n"
  "                                                                 occur.                                                      \n"
  "                                    [-r|--remove <elem,[+]pos>]  remove the element <elem> in the list at position <pos>.    \n"
  "                                                                 <pos> is the index of the element at which the insertion    \n"
  "                                                                 will occcur after, if <pos> starts with '+'. Otherwise <pos>\n"
  "                                                                 is the value of the element after which the insertion will  \n"
  "                                                                 occur.                                                      \n"
  "                                                                                                                             \n"
  "Copyright ©2024 EFREI - Rémi COHEN SCALI                                                                                     \n",
  /* ===================================================================================================================== 1 = */
  /*  == $ lisetchainee -v                                                                                                   = */
  "listechainee: info: option 'v' was incremented for verbosity !\n"
  "listechainee: error: no option was specified!\n"
  "listechainee: usage: listechainee [-hvdxXqNi] [-l|-s <filename>] [-t|-A|-P <elem>] [-I|-r <elem,[+]pos>]                     \n"
  "                                 Options:                                                                                    \n"
  "                                 Options:                                                                                    \n"
  "                                    [-h|--help]                  display this help message                                   \n"
  "                                    [-v|--verbose]               increase verbosity                                          \n"
  "                                 Commands:                                                                                   \n"
  "                                    [-i|--init]                  init a linked list                                          \n"
  "                                    [-l|--load <filename>]       load a linked list from a file <filename>                   \n"
  "                                    [-s|--save <filename>]       save a linked list in a file <filename>                     \n"
  "                                    [-t|--test <elem>]           test if an element <elem> is contained in the list          \n"
  "                                    [-A|--append <elem>]         append the element <elem> in the list                       \n"
  "                                    [-P|--prepend <elem>]        prepend the element <elem> in the list                      \n"
  "                                    [-I|--insert <elem,[+]pos>]  insert the element <elem> in the list at position <pos>.    \n"
  "                                                                 <pos> is the index of the element at which the insertion    \n"
  "                                                                 will occcur after, if <pos> starts with '+'. Otherwise <pos>\n"
  "                                                                 is the value of the element after which the insertion will  \n"
  "                                                                 occur.                                                      \n"
  "                                    [-r|--remove <elem,[+]pos>]  remove the element <elem> in the list at position <pos>.    \n"
  "                                                                 <pos> is the index of the element at which the insertion    \n"
  "                                                                 will occcur after, if <pos> starts with '+'. Otherwise <pos>\n"
  "                                                                 is the value of the element after which the insertion will  \n"
  "                                                                 occur.                                                      \n"
  "                                                                                                                             \n"
  "Copyright ©2024 EFREI - Rémi COHEN SCALI                                                                                     \n",
  /* ===================================================================================================================== 2 = */
  /*  == $ lisetchainee -v -h                                                                                                = */
  "listechainee: info: option 'v' was incremented for verbosity !\n"
  "listechainee: info: option 'h' was set !\n"
  "listechainee: error: no option was specified!\n"
  "listechainee: usage: listechainee [-hvdxXqNi] [-l|-s <filename>] [-t|-A|-P <elem>] [-I|-r <elem,[+]pos>]                     \n"
  "                                 Options:                                                                                    \n"
  "                                 Options:                                                                                    \n"
  "                                    [-h|--help]                  display this help message                                   \n"
  "                                    [-v|--verbose]               increase verbosity                                          \n"
  "                                 Commands:                                                                                   \n"
  "                                    [-i|--init]                  init a linked list                                          \n"
  "                                    [-l|--load <filename>]       load a linked list from a file <filename>                   \n"
  "                                    [-s|--save <filename>]       save a linked list in a file <filename>                     \n"
  "                                    [-t|--test <elem>]           test if an element <elem> is contained in the list          \n"
  "                                    [-A|--append <elem>]         append the element <elem> in the list                       \n"
  "                                    [-P|--prepend <elem>]        prepend the element <elem> in the list                      \n"
  "                                    [-I|--insert <elem,[+]pos>]  insert the element <elem> in the list at position <pos>.    \n"
  "                                                                 <pos> is the index of the element at which the insertion    \n"
  "                                                                 will occcur after, if <pos> starts with '+'. Otherwise <pos>\n"
  "                                                                 is the value of the element after which the insertion will  \n"
  "                                                                 occur.                                                      \n"
  "                                    [-r|--remove <elem,[+]pos>]  remove the element <elem> in the list at position <pos>.    \n"
  "                                                                 <pos> is the index of the element at which the insertion    \n"
  "                                                                 will occcur after, if <pos> starts with '+'. Otherwise <pos>\n"
  "                                                                 is the value of the element after which the insertion will  \n"
  "                                                                 occur.                                                      \n"
  "                                                                                                                             \n"
  "Copyright ©2024 EFREI - Rémi COHEN SCALI                                                                                     \n",
  /* ===================================================================================================================== 3 = */
  /*  == $ lisetchainee --verbose                                                                                            = */
  "listechainee: info: option 'v' was incremented for verbosity !\n"
  "listechainee: error: no option was specified!\n"
  "listechainee: usage: listechainee [-hvdxXqNi] [-l|-s <filename>] [-t|-A|-P <elem>] [-I|-r <elem,[+]pos>]                     \n"
  "                                 Options:                                                                                    \n"
  "                                 Options:                                                                                    \n"
  "                                    [-h|--help]                  display this help message                                   \n"
  "                                    [-v|--verbose]               increase verbosity                                          \n"
  "                                 Commands:                                                                                   \n"
  "                                    [-i|--init]                  init a linked list                                          \n"
  "                                    [-l|--load <filename>]       load a linked list from a file <filename>                   \n"
  "                                    [-s|--save <filename>]       save a linked list in a file <filename>                     \n"
  "                                    [-t|--test <elem>]           test if an element <elem> is contained in the list          \n"
  "                                    [-A|--append <elem>]         append the element <elem> in the list                       \n"
  "                                    [-P|--prepend <elem>]        prepend the element <elem> in the list                      \n"
  "                                    [-I|--insert <elem,[+]pos>]  insert the element <elem> in the list at position <pos>.    \n"
  "                                                                 <pos> is the index of the element at which the insertion    \n"
  "                                                                 will occcur after, if <pos> starts with '+'. Otherwise <pos>\n"
  "                                                                 is the value of the element after which the insertion will  \n"
  "                                                                 occur.                                                      \n"
  "                                    [-r|--remove <elem,[+]pos>]  remove the element <elem> in the list at position <pos>.    \n"
  "                                                                 <pos> is the index of the element at which the insertion    \n"
  "                                                                 will occcur after, if <pos> starts with '+'. Otherwise <pos>\n"
  "                                                                 is the value of the element after which the insertion will  \n"
  "                                                                 occur.                                                      \n"
  "                                                                                                                             \n"
  "Copyright ©2024 EFREI - Rémi COHEN SCALI                                                                                     \n",
  /* ===================================================================================================================== 4 = */
  /*  == $ lisetchainee --verbose --help                                                                                     = */
  "listechainee: info: option 'v' was incremented for verbosity !\n"
  "listechainee: info: option 'h' was set !\n"
  "listechainee: error: no option was specified!\n"
  "listechainee: usage: listechainee [-hvdxXqNi] [-l|-s <filename>] [-t|-A|-P <elem>] [-I|-r <elem,[+]pos>]                     \n"
  "                                 Options:                                                                                    \n"
  "                                 Options:                                                                                    \n"
  "                                    [-h|--help]                  display this help message                                   \n"
  "                                    [-v|--verbose]               increase verbosity                                          \n"
  "                                 Commands:                                                                                   \n"
  "                                    [-i|--init]                  init a linked list                                          \n"
  "                                    [-l|--load <filename>]       load a linked list from a file <filename>                   \n"
  "                                    [-s|--save <filename>]       save a linked list in a file <filename>                     \n"
  "                                    [-t|--test <elem>]           test if an element <elem> is contained in the list          \n"
  "                                    [-A|--append <elem>]         append the element <elem> in the list                       \n"
  "                                    [-P|--prepend <elem>]        prepend the element <elem> in the list                      \n"
  "                                    [-I|--insert <elem,[+]pos>]  insert the element <elem> in the list at position <pos>.    \n"
  "                                                                 <pos> is the index of the element at which the insertion    \n"
  "                                                                 will occcur after, if <pos> starts with '+'. Otherwise <pos>\n"
  "                                                                 is the value of the element after which the insertion will  \n"
  "                                                                 occur.                                                      \n"
  "                                    [-r|--remove <elem,[+]pos>]  remove the element <elem> in the list at position <pos>.    \n"
  "                                                                 <pos> is the index of the element at which the insertion    \n"
  "                                                                 will occcur after, if <pos> starts with '+'. Otherwise <pos>\n"
  "                                                                 is the value of the element after which the insertion will  \n"
  "                                                                 occur.                                                      \n"
  "                                                                                                                             \n"
  "Copyright ©2024 EFREI - Rémi COHEN SCALI                                                                                     \n",
  /* ===================================================================================================================== 5 = */
  /*  == $ lisetchainee -A 1 -d                                                                                              = */
  "Liste: 1\n",
  /* ===================================================================================================================== 6 = */
  /*  == $ lisetchainee -P 2 -d                                                                                              = */
  "Liste: 2\n",
  /* ===================================================================================================================== 7 = */
  /*  == $ lisetchainee --append 3 --display                                                                                 = */
  "Liste: 3\n",
  /* ===================================================================================================================== 8 = */
  /*  == $ lisetchainee --prepend 4 --display                                                                                = */
  "Liste: 4\n",
  /* ===================================================================================================================== 9 = */
  /*  == $ lisetchainee -A 1 -P 2 -d                                                                                         = */
  "Liste: 2,1\n",
  /* ==================================================================================================================== 10 = */
  /*  == $ lisetchainee --append 1 --prepend 2 --display                                                                     = */
  "Liste: 2,1\n",
  /* ==================================================================================================================== 11 = */
  /*  == $ lisetchainee -v -A 1 -d                                                                                           = */
  "listechainee: info: option 'v' was incremented for verbosity !\n"
  "listechainee: info: option 'A' was called for appending '1' !\n"
  "listechainee: info: appending '1'\n"
  "listechainee: info: option 'd' was set !\n"
  "listechainee: info: Displaying list\n"
  "Liste: 1\n",
  /* ==================================================================================================================== 12 = */
  /*  == $ lisetchainee -v -P 2 -d                                                                                           = */
  "listechainee: info: option 'v' was incremented for verbosity !\n"
  "listechainee: info: option 'P' was called for prepending '2' !\n"
  "listechainee: info: prepending '2'\n"
  "listechainee: info: option 'd' was set !\n"
  "listechainee: info: Displaying list\n"
  "Liste: 2\n",
  /* ==================================================================================================================== 13 = */
  /*  == $ lisetchainee --verbose --append 3 --display                                                                       = */
  "listechainee: info: option 'v' was incremented for verbosity !\n"
  "listechainee: info: option 'A' was called for appending '3' !\n"
  "listechainee: info: appending '3'\n"
  "listechainee: info: option 'd' was set !\n"
  "listechainee: info: Displaying list\n"
  "Liste: 3\n",
  /* ==================================================================================================================== 14 = */
  /*  == $ lisetchainee --verbose --prepend 4 --display                                                                      = */
  "listechainee: info: option 'v' was incremented for verbosity !\n"
  "listechainee: info: option 'P' was called for prepending '4' !\n"
  "listechainee: info: prepending '4'\n"
  "listechainee: info: option 'd' was set !\n"
  "listechainee: info: Displaying list\n"
  "Liste: 4\n",
  /* ==================================================================================================================== 15 = */
  /*  == $ lisetchainee -v -A 1 -P 2 -d                                                                                      = */
  "listechainee: info: option 'v' was incremented for verbosity !\n"
  "listechainee: info: option 'A' was called for appending '1' !\n"
  "listechainee: info: appending '1'\n"
  "listechainee: info: option 'P' was called for prepending '2' !\n"
  "listechainee: info: prepending '2'\n"
  "listechainee: info: option 'd' was set !\n"
  "listechainee: info: Displaying list\n"
  "Liste: 2,1\n",
  /* ==================================================================================================================== 16 = */
  /*  == $ lisetchainee --verbose --append 1 --prepend 2 --display                                                           = */
  "listechainee: info: option 'v' was incremented for verbosity !\n"
  "listechainee: info: option 'A' was called for appending '1' !\n"
  "listechainee: info: appending '1'\n"
  "listechainee: info: option 'P' was called for prepending '2' !\n"
  "listechainee: info: prepending '2'\n"
  "listechainee: info: option 'd' was set !\n"
  "listechainee: info: Displaying list\n"
  "Liste: 2,1\n",
  /* ==================================================================================================================== 17 = */
  /*  == $ lisetchainee -v -A 1 -P 2 -d -s testlist1.l                                                                       = */
  "listechainee: info: option 'v' was incremented for verbosity !\n"
  "listechainee: info: option 'A' was called for appending '1' !\n"
  "listechainee: info: appending '1'\n"
  "listechainee: info: option 'P' was called for prepending '2' !\n"
  "listechainee: info: prepending '2'\n"
  "listechainee: info: option 'd' was set !\n"
  "listechainee: info: Displaying list\n"
  "Liste: 2,1\n"
  "listechainee: info: option 's' was called for file 'testlist1.l' !\n"
  "listechainee: info: Loading/Saving from/to filename 'testlist1.l'\n"
  "listechainee: info: list was successfully saved to file 'testlist1.l'\n",
  /* ==================================================================================================================== 18 = */
  /*  == $ lisetchainee --verbose --append 1 --prepend 2 --display --save testlist1.l                                        = */
  "listechainee: info: option 'v' was incremented for verbosity !\n"
  "listechainee: info: option 'A' was called for appending '1' !\n"
  "listechainee: info: appending '1'\n"
  "listechainee: info: option 'P' was called for prepending '2' !\n"
  "listechainee: info: prepending '2'\n"
  "listechainee: info: option 'd' was set !\n"
  "listechainee: info: Displaying list\n"
  "Liste: 2,1\n"
  "listechainee: info: option 's' was called for file 'testlist1.l' !\n"
  "listechainee: info: Loading/Saving from/to filename 'testlist1.l'\n"
  "listechainee: info: list was successfully saved to file 'testlist1.l'\n",
  /* ==================================================================================================================== 19 = */
  /*  == $ lisetchainee -v -l testlist1.l -d                                                                                 = */
  "listechainee: info: option 'v' was incremented for verbosity !\n"
  "listechainee: info: option 'l' was called for file 'testlist1.l' !\n"
  "listechainee: info: Loading/Saving from/to filename 'testlist1.l'\n"
  "listechainee: info: list was successfully loaded from file 'testlist1.l'\n"
  "listechainee: info: option 'd' was set !\n"
  "listechainee: info: Displaying list\n"
  "Liste: 2,1\n",
  /* ==================================================================================================================== 20 = */
  /*  == $ lisetchainee -v -l testlist1.l -d                                                                                 = */
  "listechainee: info: option 'v' was incremented for verbosity !\n"
  "listechainee: info: option 'l' was called for file 'testlist1.l' !\n"
  "listechainee: info: Loading/Saving from/to filename 'testlist1.l'\n"
  "listechainee: info: list was successfully loaded from file 'testlist1.l'\n"
  "listechainee: info: option 'd' was set !\n"
  "listechainee: info: Displaying list\n"
  "Liste: 2,1\n",
  /* ==================================================================================================================== 21 = */
  /*  == The End                                                                                                             = */
  NULL
  /*  ==                                                                                                      NB_TESTS == 22 = */
};

#define TEST_COMMAND_ARGS_VS_RESULT_NB(args, nb)                    \
  /* Initialize the buffer to \x00 */                               \
  bzero((void*)buf, BUFFER_MAX_SIZE);                               \
  /* Open the command with a pipe */                                \
  FILE *fp = popen_listechainee(args);                              \
  /* Read the command output with the pipe */                       \
  fread(buf, BUFFER_MAX_SIZE-1, 1, fp);                             \
  /* Test assertion */                                              \
  CU_ASSERT(strncmp(buf, results[nb], strlen(results[nb])) == 0);   \
  /* Close the pipe */                                              \
  pclose(fp);

/*
 * test_command_basic_invocation_0
 *
 * Basic tests for the command invocation without args
 */
void
test_command_basic_invocation_0(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("", 0);
}

/*
 * test_command_basic_invocation_v
 *
 * Basic tests for the command invocation with '-v' arg
 */
void
test_command_basic_invocation_v(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("-v", 1);
}

/*
 * test_command_basic_invocation_vh
 *
 * Basic tests for the command invocation with '-v -h' args
 */
void
test_command_basic_invocation_vh(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("-v -h", 2);
}

/*
 * test_command_basic_invocation_verbose
 *
 * Basic tests for the command invocation with '--verbose' arg
 */
void
test_command_basic_invocation_verbose(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("--verbose", 3);
}

/*
 * test_command_basic_invocation_verbose_help
 *
 * Basic tests for the command invocation with '--verbose --help' args
 */
void
test_command_basic_invocation_verbose_help(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("--verbose --help", 4);  
}

/*
 * test_command_basic_invocation_A1d
 *
 * Basic tests for the command invocation with '-A 1 -d' args
 */
void
test_command_basic_invocation_A1d(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("-A 1 -d", 5);
}

/*
 * test_command_basic_invocation_P2d
 *
 * Basic tests for the command invocation with '-P 2 -d' args
 */
void
test_command_basic_invocation_P2d(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("-P 2 -d", 6);
}

/*
 * test_command_basic_invocation_append_3_display
 *
 * Basic tests for the command invocation with '--append 3 --display' args
 */
void
test_command_basic_invocation_append_3_display(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("--append 3 --display", 7);  
}

/*
 * test_command_basic_invocation_prepend_4_display
 *
 * Basic tests for the command invocation with '--prepend 4 --display' args
 */
void
test_command_basic_invocation_prepend_4_display(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("--prepend 4 --display", 8);  
}

/*
 * test_command_basic_invocation_A1P2d
 *
 * Basic tests for the command invocation with '-A 1 -P 2 -d' args
 */
void
test_command_basic_invocation_A1P2d(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("-A 1 -P 2 -d", 9);  
}

/*
 * test_command_basic_invocation_append_1_prepend_2_display
 *
 * Basic tests for the command invocation with '--append 1 --prepend 2 --display' args
 */
void
test_command_basic_invocation_append_1_prepend_2_display(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("--append 1 --prepend 2 --display", 10);  
}

/*
 * test_command_basic_invocation_vA1d
 *
 * Basic tests for the command invocation with '-v -A 1 -d' args
 */
void
test_command_basic_invocation_vA1d(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("-v -A 1 -d", 11);
}

/*
 * test_command_basic_invocation_vP2d
 *
 * Basic tests for the command invocation with '-v -P 2 -d' args
 */
void
test_command_basic_invocation_vP2d(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("-v -P 2 -d", 12);
}

/*
 * test_command_basic_invocation_verbose_append_3_display
 *
 * Basic tests for the command invocation with '--verbose --append 3 --display' args
 */
void
test_command_basic_invocation_verbose_append_3_display(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("--verbose --append 3 --display", 13);  
}

/*
 * test_command_basic_invocation_verbose_prepend_4_display
 *
 * Basic tests for the command invocation with '--verbose --prepend 4 --display' args
 */
void
test_command_basic_invocation_verbose_prepend_4_display(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("--verbose --prepend 4 --display", 14);  
}

/*
 * test_command_basic_invocation_vA1P2d
 *
 * Basic tests for the command invocation with '-v -A 1 -P 2 -d' args
 */
void
test_command_basic_invocation_vA1P2d(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("-v -A 1 -P 2 -d", 15);  
}

/*
 * test_command_basic_invocation_verbose_append_1_prepend_2_display
 *
 * Basic tests for the command invocation with '--verbose --append 1 --prepend 2 --display' args
 */
void
test_command_basic_invocation_verbose_append_1_prepend_2_display(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("--verbose --append 1 --prepend 2 --display", 16);  
}

/*
 * test_command_basic_invocation_vA1P2ds_testlist1_l
 *
 * Basic tests for the command invocation with '-v -A 1 -P 2 -d -s testlist1.l' args
 */
void
test_command_basic_invocation_vA1P2ds_testlist1_l(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("-v -A 1 -P 2 -d -s testlist1.l", 17);
  /* Open the saved list file */ 
  FILE* datafp = fopen("testlist1.l", "r");
  /* Open failed */
  if (datafp == (FILE*)NULL)
    {
      /* Couldn't read the list file, format error msg  */
      char errmesg[ERROR_BUFFER_SIZE];
      snprintf(errmesg, ERROR_BUFFER_SIZE-1, "error: ");
      perror(errmesg);
      /* Test failed */
      CU_ASSERT(0 == 1);
    }
  else
    {
      /* Buffer for reading file content */
      char buflist[LIST_BUFFER_SIZE];
      /* Read list file content */
      size_t listlen = fread(buflist, LIST_BUFFER_SIZE-1, 1, datafp);
      /* Assert the list content */
      CU_ASSERT(strncmp("2,1", buflist, listlen) == 0);
    }
  return;
}

/*
 * test_command_basic_invocation_verbose_append_1_prepend_2_display_save_testlist1_l
 *
 * Basic tests for the command invocation with '--verbose --append 1 --prepend 2 --display --save testlist1.l' args
 */
void
test_command_basic_invocation_verbose_append_1_prepend_2_display_save_testlist1_l(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("--verbose --append 1 --prepend 2 --display --save testlist1.l", 18); 
  /* Open the saved list file */ 
  FILE* datafp = fopen("testlist1.l", "r");
  /* Open failed */
  if (datafp == (FILE*)NULL)
    {
      /* Couldn't read the list file, format error msg  */
      char errmesg[ERROR_BUFFER_SIZE];
      snprintf(errmesg, ERROR_BUFFER_SIZE-1, "error: ");
      perror(errmesg);
      /* Test failed */
      CU_ASSERT(0 == 1);
    }
  else
    {
      /* Buffer for reading file content */
      char buflist[LIST_BUFFER_SIZE];
      /* Read list file content */
      size_t listlen = fread(buflist, LIST_BUFFER_SIZE-1, 1, datafp);
      /* Assert the list content */
      CU_ASSERT(strncmp("2,1", buflist, listlen) == 0);
    }
  return;
}

/*
 * test_command_basic_invocation_vl_testlist1_l_d
 *
 * Basic tests for the command invocation with '-v -l testlist1.l -d' args
 */
void
test_command_basic_invocation_vl_testlist1_l_d(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("-v -l testlist1.l -d", 19); 
}

/*
 * test_command_basic_invocation_verbose_load_testlist1_l_display
 *
 * Basic tests for the command invocation with '--verbose --load testlist1.l --display' args
 */
void
test_command_basic_invocation_verbose_load_testlist1_l_display(void)
{
  TEST_COMMAND_ARGS_VS_RESULT_NB("--verbose --load testlist1.l --display", 20); 
}
