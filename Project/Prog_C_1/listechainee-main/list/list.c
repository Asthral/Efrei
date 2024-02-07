/*
 * list.c
 *
 * Operation de base de manipulation d'une liste chainee
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "list/list.h"

#define ERR_MESSAGE_MAX_SIZE 	1024
#define BUFFER_MAX_SIZE 		  20

/* Extern decl of current listechainee */
extern listechainee_ptr curlist;
/* Extern decl of program name */
extern char* progname;

/*
 * free_list
 *
 * Take a list as input and free all nodes in it
 * params:
 *   list - in: list to free
 * returns:
 *   void
 */
void
free_list(listechainee_ptr list)
{
  while(list)
    {
      listechainee_ptr tmp = list;
      list = list->next;
      free(tmp);
    }
}

/*
 * init_list
 *
 * Initialize the current list as a NULL list. If curlist
 * is not null, free it.
 * params:
 *   void
 * returns:
 *   void
 */
void
init_list(void)
{
  if (curlist != NULL)
    free_list(curlist);
  curlist = NULL;
}

/*
 * reinit_list
 *
 * Re-initialize the current list as the list provided. If curlist
 * is not null, free it.
 * params:
 *   void
 * returns:
 *   void
 */
listechainee_ptr
reinit_list(listechainee_ptr list)
{
  init_list();
  return (curlist = list);
}

/*
 * display_list
 *
 * Take a list as input and displays all nodes in it. If list
 * is null, displays "Empty list".
 * params:
 *   list - in: the list to display
 * returns:
 *   void
 */
void
display_list(listechainee_ptr list)
{
  if (list == NULL)
    fprintf(stdout, "Liste vide\n");
  else
    {
      fprintf(stdout, "Liste: ");
      while(list)
        {
          fprintf(stdout, "%d", list->N);
          if (list->next)
            fprintf(stdout, ",");
          list = list->next;
        }
      fprintf(stdout, "\n");
    }
}

/*
 * load_list
 *
 * Load a linked list from the file named <filename>.
 * If loading fails, NULL is returned.
 * params:
 *   filename - in: the name of the file to load the list from
 * returns:
 *   the loaded list if successfull
 *   NULL otherwise
 */
listechainee_ptr
load_list(char* filename)
{
  /* Reinit the current list */
  listechainee_ptr list = reinit_list(curlist);
  /* Open the file 'filename' for reading */
  FILE *fp = fopen(filename, "r");
  /* File opening failed */
  if (fp == (FILE*)NULL)
    {
      /* Format the error message */
      char errmesg[ERR_MESSAGE_MAX_SIZE];
      snprintf(errmesg, ERR_MESSAGE_MAX_SIZE-1, "error: loading list from file '%s'", filename);
      /* Displays it */
      perror(errmesg);
      /* Return an error */
      return NULL;
    }
  /* File opened successfully */
  else
    {
      /* Buffer for reading the file */
      char s[BUFFER_MAX_SIZE];
      /* Pointers (start/end) used for parsing integers */
      char* s_ptr = (char*)NULL;
      char* e_ptr = (char*)NULL;
      /* While we can read a line from file */
      while ((s_ptr = fgets(s, BUFFER_MAX_SIZE-1, fp)) != (char*)NULL)
        {
          do
            {
              /* Parse integer from start and record the end */
              int n = (int)strtol(s_ptr, &e_ptr, 10);
              /* If end is a comma ',' */
              if (*e_ptr == ',')
                /* For next integer, starts after comma */
                s_ptr = e_ptr+1;
              else
                /* Else start where we stopped */
                s_ptr = e_ptr;
              /* Append read integer as a new list element */
              list = append_list(list, n);
            }
          /* While we didn't reach end of line or end of file */
          while(*s_ptr != '\n' && *s_ptr != EOF);
        }
    }
  /* Return the new list */
  return list;
}

/*
 * save_list
 *
 * Save a linked list to the file named <filename>.
 * If saving fails, NULL is returned.
 * params:
 *   filename - in: the name of the file to save the list to
 * returns:
 *   the saved list if successfull
 *   NULL otherwise
 */
listechainee_ptr
save_list(listechainee_ptr list, char* filename)
{
  /* Opens file 'filename' for writing */
  FILE *fp = fopen(filename, "w");
  /* If file didn't opened successfully */
  if (fp == (FILE *)NULL)
    {
      /* Format error message */
      char errmesg[ERR_MESSAGE_MAX_SIZE];
      snprintf(errmesg, ERR_MESSAGE_MAX_SIZE-1, "error: loading list from file '%s'", filename);
      /* And displays it */
      perror(errmesg);
      /* Returns error */
      return NULL;
    }
  /* File opened successfully */
  else
    {
      /* Browse the list */
      listechainee_ptr tmp = list;
      while (tmp)
        {
          /* Print the current element */
          fprintf(fp, "%d", tmp->N);
          /* If there is still some elements, add a comma */
          if (tmp->next)
            fprintf(fp, ",");
          /* Next element */
          tmp = tmp->next;
        }
      /* At end of list add a new line */
      fprintf(fp, "\n");
      /* Close the file */
      fclose(fp);
    }
  /* Return the list */
  return list;
}

/*
 * test_elem_in_list
 *
 * Take a list and an elem as input, and returns if this elem is
 * contained in this list.
 * params:
 *   list - in: the list in which to test if elem is in
 *   n    - in: the element to test
 * returns:
 *   0: if elem is not in the list
 *   1: if elem is in the list
 */
int
test_elem_in_list(listechainee_ptr list, int n)
{
  /* Browse the list */
  listechainee_ptr tmp = list;
  while(tmp)
    {
      /* If element was found */
      if (tmp->N == n)
        /* Returns success */
        return 1;
      /* Next element */
      tmp = tmp->next;
    }
  /* Returns failure */
  return 0;
}

/*
 * test_ix_in_list
 *
 * Take a list and an index as input, and returns if this index is
 * contained in this list (number of elem in list > ix).
 * params:
 *   list - in: the list in which to test if elem is in
 *   ix   - in: the element to test
 * returns:
 *   0: if ix is not in the list
 *   1: if ix is in the list or ix == 0 & list is NULL
 */
int
test_ix_in_list(listechainee_ptr list, int ix)
{
  /* If ix not positive or null */
  if (ix < 0)
    /* returns No */
    return 0;
  /* Local index */
  int lix = 1;
  /* Temp node ptr */
  listechainee_ptr tmp = list;
  /* Browse the list */
  while(tmp)
    {
      /* If index is found */
      if (lix == ix)
        /* Return Yes */
        return 1;
      /* Goes on next node */
      tmp = tmp->next;
      /* Incr local index (next one) */
      lix++;
    }
  /* If index was null it is always available else return No */
  return ix == 0 ? 1 : 0;
}

/*
 * append_list
 *
 * Take a list and element as input and append the element
 * at the end of the list.
 * params:
 *   list - in: list in which to append the new element
 *   n    - in: element to append to the list
 * returns:
 *   the list
 */
listechainee_ptr
append_list(listechainee_ptr list, int n)
{
  if (test_elem_in_list(list, n))
    return NULL;
  
  listechainee_ptr new_node = (listechainee_ptr)malloc(sizeof(struct listechainee_st));
  new_node->N = n;
  new_node->next = (listechainee_ptr)NULL;
  if (list == NULL)
    {
      list = new_node;
    }
  else
    {
      listechainee_ptr tmp = list;
      while(tmp)
        {
          if (tmp->next == NULL)
            break;
          tmp = tmp->next;
        }
      tmp->next = new_node;
    }
  return list;  
}

/*
 * prepend_list
 *
 * Take a list and element as input and prepend the element
 * at the start of the list.
 * params:
 *   list - in: list in which to prepend the new element
 *   n    - in: element to prepend to the list
 * returns:
 *   the list
 */
listechainee_ptr 
prepend_list(listechainee_ptr list, int n)
{
  if (test_elem_in_list(list, n))
    return NULL;
  
  listechainee_ptr new_node = (listechainee_ptr)malloc(sizeof(struct listechainee_st));
  new_node->N = n;
  new_node->next = list;
  list = new_node;

  return list;
}

/*
 * insert_elem_in_list
 *
 * Take a list, an element and an index as input and insert the element 'n'
 * in the list 'list' at the index 'ix'. if index is not in list or if
 * element is already in list, returns NULL.
 * params:
 *   list - in: the list in which to insert the element
 *   ix   - in: the index at which the element has to be inserted
 *   n    - in: the element to insert in the list at the index
 * returns:
 *   the list if the element is not in the list and was inserted
 *   NULL otherwhise
 */
listechainee_ptr
insert_elem_in_list(listechainee_ptr list, int ix, int n)
{
  /* First test pre conditions: ix in list and elem not in list */
  if (test_ix_in_list(list, ix) && !test_elem_in_list(list, n))
    {
      /* local ix */
      int lix = 0;
      /* tmp node ptr */
      listechainee_ptr tmp = list;
      /* while tmp not null */
      while(tmp)
        {
          /* If index was found */
          if (lix == ix)
            {
              /* Allocate new node */
              listechainee_ptr newn = (listechainee_ptr)malloc(sizeof(struct listechainee_st));
              if (newn == NULL)
                /* Mem alloc pb */
                return NULL;
              /* Init node */
              newn->N = n;
              /* If index is 0, insert at start of list */
              if (ix == 0)
                {
                  /* New node is the new list */
                  newn->next = tmp->next;
                  /* Then returns it */
                  return newn;
                }
              /* Insert in the list (after the first element) */
              else
                {
                  /* Link new node to next node */
                  newn->next = tmp->next;
                  /* Insert new node */
                  tmp->next = newn;
                  /* Returns list */
                  return list;                  
                }
            }
          /* Goes on to next node */
          tmp = tmp->next;
          /* And incr local ix */
          lix++;
        }      
    }
  else
    /* returns NULL: cannot insert */
    return(NULL);
}

void
delete_end_of_list(listechainee_ptr list)
{
  
}

listechainee_ptr
delete_start_of_list(listechainee_ptr list)
{
  
} 

listechainee_ptr
delete_elem_in_list(listechainee_ptr list, int ix)
{
  
}

