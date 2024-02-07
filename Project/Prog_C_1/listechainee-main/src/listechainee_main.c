/*
 * listechainee_main.c
 *
 * Fichier source principale du menu de gestion de liste chainee
 * Affiche le menu, saisie la commande a executer puis lance la commande
 */

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>

#include "list/list.h"

/* Forward decl main */
int main(int argc, char** argv);

/* Long options specification: see 'man 3 getopt' */
static struct option long_options[] =
  {
    {"help",    no_argument,       0,  'h' },
    {"verbose", no_argument,       0,  'v' },
    {"display", no_argument,       0,  'd' },
    {"init",    no_argument,       0,  'i' },
    {"load",    required_argument, 0,  'l' },
    {"save",    required_argument, 0,  's' },
    {"test",    required_argument, 0,  't' },
    {"append",  required_argument, 0,  'A' },
    {"prepend", required_argument, 0,  'P' },
    {"insert",  required_argument, 0,  'I' },
    {"del",     no_argument,       0,  'x' },
    {"delend",  no_argument,       0,  'X' },
    {"remove",  required_argument, 0,  'r' },
    {"quit",    no_argument,       0,  'q' },
    {"inter",   no_argument,       0,  'N' },
    {0,         0,                 0,  0 }
  };
    
/* List chainee courante */
listechainee_ptr curlist = (listechainee_ptr)NULL;

/*
 * Options variables
 */
extern char* optarg;			// Option argument pointer
static int one_opt = 0;			// Option set if no command were requested (error)
static int v_opt = 0;			// Option for verbosity
static int h_opt = 0;			// Option for help
static int d_opt = 0;			// Option for displaying list 
static int l_opt = 0;			// Option for loading file
static int s_opt = 0;			// Option for saving file
static int i_opt = 0;			// Option for initializing the list
static int t_opt = 0;			// Option for testing element
static int A_opt = 0;			// Option for appending element
static int P_opt = 0;			// Option for prepending element
static int I_opt = 0;			// Option for inserting element
static int x_opt = 0;			// Option for deleting last element
static int X_opt = 0;			// Option for deleting first element
static int r_opt = 0;			// Option for removing specific element
static int q_opt = 0;			// Option for quitting
static int N_opt = 0;			// Option for entering interactive menu

char *progname = (char *)NULL;			// Program name
char *blankname = (char *)NULL;			// Blanked program name
char* arg_filename = (char *)NULL;		// Argument handling filename
int arg_elem = 0;						// Argument handling element

/*
 * print_help
 *
 * The help message to be printed when -h option is requested
 */
void
print_help(void)
{
  fprintf(stdout, "%s: usage: %s [-hvdxXqNi] [-l|-s <filename>] [-t|-A|-P <elem>] [-I|-r <elem,[+]pos>]                     \n", progname, progname);
  fprintf(stdout, "%s         %sOptions:                                                                                    \n", blankname, blankname);
  fprintf(stdout, "%s         %sOptions:                                                                                    \n", blankname, blankname);
  fprintf(stdout, "%s         %s   [-h|--help]                  display this help message                                   \n", blankname, blankname);
  fprintf(stdout, "%s         %s   [-v|--verbose]               increase verbosity                                          \n", blankname, blankname);
  fprintf(stdout, "%s         %sCommands:                                                                                   \n", blankname, blankname);
  fprintf(stdout, "%s         %s   [-i|--init]                  init a linked list                                          \n", blankname, blankname);
  fprintf(stdout, "%s         %s   [-l|--load <filename>]       load a linked list from a file <filename>                   \n", blankname, blankname);
  fprintf(stdout, "%s         %s   [-s|--save <filename>]       save a linked list in a file <filename>                     \n", blankname, blankname);
  fprintf(stdout, "%s         %s   [-t|--test <elem>]           test if an element <elem> is contained in the list          \n", blankname, blankname);
  fprintf(stdout, "%s         %s   [-A|--append <elem>]         append the element <elem> in the list                       \n", blankname, blankname);
  fprintf(stdout, "%s         %s   [-P|--prepend <elem>]        prepend the element <elem> in the list                      \n", blankname, blankname);
  fprintf(stdout, "%s         %s   [-I|--insert <elem,[+]pos>]  insert the element <elem> in the list at position <pos>.    \n", blankname, blankname);
  fprintf(stdout, "%s         %s                                <pos> is the index of the element at which the insertion    \n", blankname, blankname);
  fprintf(stdout, "%s         %s                                will occcur after, if <pos> starts with '+'. Otherwise <pos>\n", blankname, blankname);
  fprintf(stdout, "%s         %s                                is the value of the element after which the insertion will  \n", blankname, blankname);
  fprintf(stdout, "%s         %s                                occur.                                                      \n", blankname, blankname);
  fprintf(stdout, "%s         %s   [-r|--remove <elem,[+]pos>]  remove the element <elem> in the list at position <pos>.    \n", blankname, blankname);
  fprintf(stdout, "%s         %s                                <pos> is the index of the element at which the insertion    \n", blankname, blankname);
  fprintf(stdout, "%s         %s                                will occcur after, if <pos> starts with '+'. Otherwise <pos>\n", blankname, blankname);
  fprintf(stdout, "%s         %s                                is the value of the element after which the insertion will  \n", blankname, blankname);
  fprintf(stdout, "%s         %s                                occur.                                                      \n", blankname, blankname);
  fprintf(stdout, "%s         %s                                                                                            \n", blankname, blankname);
  fprintf(stdout, "Copyright ©2024 EFREI - Rémi COHEN SCALI %s%s                                                            \n", blankname, blankname);
}

/*
 * main
 *
 * The main function being the program entry point
 */
int main(int argc, char** argv)
{
  /* The variable holding the command line argument */
  int c;
  /* Option index digit */
  int digit_optind = 0;

  /* Extract the program name from the first argument */
  progname = (progname = rindex(argv[0], '/')) ? progname+1 : argv[0];
  /* Allocate memory for converting program name into blank string */
  blankname = strndup(progname, strlen(progname));
  /* Actually convert the program name into blank string */
  blankname = memset(blankname, (int)' ', strlen(progname));
  /* Initialize the linked list */ 
  init_list();

  /* Look */
  while (1) {
    int this_option_optind = optind ? optind : 1;
    int option_index = 0;

    c = getopt_long(argc, argv, "hvdl:s:i:t:A:P:I:xXr:qN",
                    long_options, &option_index);
    if (c == -1)
      break;
               
    switch (c) {

    case 'h':
      h_opt = 1;
      if (v_opt)
        fprintf(stdout, "%s: info: option 'h' was set !\n", progname);
      break;

    case 'v':
      v_opt++;
      if (v_opt)
        fprintf(stdout, "%s: info: option 'v' was incremented for verbosity !\n", progname);
      break;

    case 'd':
      d_opt = 1;
      if (v_opt)
        fprintf(stdout, "%s: info: option 'd' was set !\n", progname);
      break;

    case 'i':
      i_opt = 1;
      if (v_opt)
        fprintf(stdout, "%s: info: option 'i' was set !\n", progname);
      break;

    case 'l':
      l_opt = 1;
      arg_filename = optarg;
      if (v_opt)
        fprintf(stdout, "%s: info: option 'l' was called for file '%s' !\n", progname, arg_filename);
      break;

    case 's':
      s_opt = 1;
      arg_filename = optarg;
      if (v_opt)
        fprintf(stdout, "%s: info: option 's' was called for file '%s' !\n", progname, arg_filename);
      break;

    case 't':
      t_opt = 1;
      arg_elem = atoi(optarg);
      if (v_opt)
        fprintf(stdout, "%s: info: option 't' was called for elem '%d' !\n", progname, arg_elem);
      break;

    case 'A':
      A_opt = 1;
      arg_elem = atoi(optarg);
      if (v_opt)
        fprintf(stdout, "%s: info: option 'A' was called for appending '%d' !\n", progname, arg_elem);
      break;

    case 'P':
      P_opt = 1;
      arg_elem = atoi(optarg);
      if (v_opt)
        fprintf(stdout, "%s: info: option 'P' was called for prepending '%d' !\n", progname, arg_elem);
      break;

    case 'I':
      I_opt = 1;
      arg_elem = atoi(optarg);
      if (v_opt)
        fprintf(stdout, "%s: info: option 'I' was called with elem '%d' !\n", progname, arg_elem);
      break;

    case 'x':
      x_opt = 1;
      if (v_opt)
        fprintf(stdout, "%s: info: option 'x' was set !\n", progname);
      break;

    case 'X':
      X_opt = 1;
      if (v_opt)
        fprintf(stdout, "%s: info: option 'X' was set !\n", progname);
      break;

    case 'r':
      r_opt = 1;
      arg_elem = atoi(optarg);
      if (v_opt)
        fprintf(stdout, "%s: info: option 'r' was called with elem '%d' !\n", progname, arg_elem);
      break;

    case 'q':
      q_opt = 1;
      if (v_opt)
        fprintf(stdout, "%s: info: option 'q' was set !\n", progname);
      break;

    case 'N':
      N_opt = 1;
      if (v_opt)
        fprintf(stdout, "%s: info: option 'N' was set ! Entering interactive menu ...\n", progname);
      break;

    case '?':
      break;

    default:
      printf("?? getopt returned character code 0%o ??\n", c);
    }

    if (A_opt)
      {
        /* Set not missing command option to false */
        one_opt = 1;
        if (v_opt)
          fprintf(stdout, "%s: info: appending '%d'\n", progname, arg_elem);
        A_opt = 0;
        listechainee_ptr tmplist = append_list(curlist, arg_elem);
        if (tmplist == NULL)
          fprintf(stdout, "%s: error: element '%d' already in list\n", progname, arg_elem);
        else
          curlist = tmplist;
      }
    else if (P_opt)
      {
        /* Set not missing command option to false */
        one_opt = 1;
        if (v_opt)
          fprintf(stdout, "%s: info: prepending '%d'\n", progname, arg_elem);
        P_opt = 0;
        listechainee_ptr tmplist = prepend_list(curlist, arg_elem);
        if (tmplist == NULL)
          fprintf(stdout, "%s: error: element '%d' already in list\n", progname, arg_elem);
        else
          curlist = tmplist;
      }
    else if (d_opt)
      {
        /* Set not missing command option to false */
        one_opt = 1;
        if (v_opt)
          fprintf(stdout, "%s: info: Displaying list\n", progname);
        d_opt = 0;
        display_list(curlist);
      }
    else if (x_opt || X_opt)
      {
        /* Set not missing command option to false */
        one_opt = 1;
        if (v_opt)
          fprintf(stdout, "%s: info: Deleting element\n", progname);
        x_opt = X_opt = 0;
      }
    else if (i_opt)
      {
        one_opt = 1;        
        if (v_opt)
          fprintf(stdout, "%s: info: Initializing current list !\n", progname);
        init_list();
      }
    else if (l_opt || s_opt)
      {
        /* Set not missing command option to false */
        one_opt = 1;        
        if (v_opt)
          fprintf(stdout, "%s: info: Loading/Saving from/to filename '%s'\n", progname, arg_filename);
        if (l_opt)
          {
            curlist = load_list(arg_filename);
            if (curlist == NULL)
              fprintf(stderr, "%s: error: cannot load list from file\n", progname);
            else
              if (v_opt)
                fprintf(stdout, "%s: info: list was successfully loaded from file '%s'\n", progname, arg_filename);
          }
        else if (s_opt)
          {            
            if (save_list(curlist, arg_filename) == NULL)
              fprintf(stderr, "%s: error: cannot save list to file\n", progname);
            else
              if (v_opt)
                fprintf(stdout, "%s: info: list was successfully saved to file '%s'\n", progname, arg_filename);
          }
        l_opt = s_opt = 0;
      }
    else if (t_opt)
      {
        /* Set not missing command option to false */
        one_opt = 1;        
        if (v_opt)
          fprintf(stdout, "%s: info: testing element\n", progname);
        t_opt = 0;
      }
    else if (I_opt)
      {
        /* Set not missing command option to false */
        one_opt = 1;        
        if (v_opt)
          fprintf(stdout, "%s: info: inserting element\n", progname);
        I_opt = 0;
      }
    else if (r_opt)
      {
        /* Set not missing command option to false */
        one_opt = 1;        
        if (v_opt)
          fprintf(stdout, "%s: info: removing element\n", progname);
        r_opt = 0;
      }
  }

  if (one_opt == 0)
    {
      fprintf(stdout, "%s: error: no option was specified!\n", progname);
      print_help();
    }
  else
    {
      if (optind < argc)
        {
          printf("non-option ARGV-elements: ");
          while (optind < argc)
            printf("%s ", argv[optind++]);
          printf("\n");
        }
      else if (h_opt)
        print_help();
      else if (q_opt)
        {
          
        }
      else if (N_opt)
        {
          
        }
    }
  
  return 0;
}
