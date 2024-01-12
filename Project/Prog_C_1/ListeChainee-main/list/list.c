/*
 * list.c
 *
 * Operation de base de manipulation d'une liste chainee
 */

#include "list.h"

/* Extern decl of current listchainee */
extern listchainee_ptr curlist;

void
free_list(listchainee_ptr list)
{
  while(curlist)
    {
      listchainee_ptr tmp = curlist;
      curlist = curlist->next;
      free(tmp);
    }
}

listchainee_ptr
init_list(void)
{
  if (curlist != NULL)
    free_list(curlist);
  curlist = NULL;
}

listchainee_ptr
reinit_list(listchainee_ptr list)
{
  
}

listchainee_ptr
load_list(char* filename)
{
  
}

void
save_list(char* filename)
{
  
}

int
test_elem_in_list(listchainee_ptr list, int n)
{
  listchainee_ptr tmp = list;
  if (tmp == NULL)
    return 0;
  while(tmp)
    {
      if (tmp->N == n)
        return 1;
      tmp = tmp->next;
    }
  return 0;
}

int
test_ix_in_list(listchainee_ptr list, int ix)
{
  int lix = 0;
  listchainee_ptr tmp = list;
  if (tmp == NULL)
    return 0;
  while(tmp)
    {
      if (lix == ix)
        return 1;
      tmp = tmp->next;
      lix++;
    }
  return 0;
}

void
append_list(listchainee_ptr list, int n)
{
  
}

void
prepend_list(listchainee_ptr list, int n)
{
  
}

listchainee_ptr
insert_elem_in_list(listchainee_ptr list, int ix, int n)
{
  if (test_ix_in_list(list, ix))
    {
      int lix = 0;
      listchainee_ptr tmp = list;
      while(tmp)
        {
          if (lix == ix)
            {
              listchainee_ptr newn = (listchainee_ptr)malloc(sizeof(struct listchainee_st));
              if (newn == NULL)
                return NULL;
              newn->N = n;
              if (ix == 0)
                {
                  newn->next = tmp->next;
                  return newn;
                }
              else
                {
                  newn->next = tmp->next;
                  tmp->next = newn;
                  return list;                  
                }
            }
          tmp = tmp->next;
          lix++;
        }      
    }
  else
    return(NULL);
}

void
delete_end_of_list(listchainee_ptr list)
{
  
}

listchainee_ptr
delete_start_of_list(listchainee_ptr list)
{
  
} 

listchainee_ptr
delete_elem_in_list(listchainee_ptr list, int ix)
{
  
}

