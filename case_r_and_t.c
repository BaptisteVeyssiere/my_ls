/*
** case_r_and_t.c for my_ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Thu Nov 26 17:44:27 2015 Baptiste veyssiere
** Last update Thu Nov 26 19:35:37 2015 Baptiste veyssiere
*/

#include "file_struct.h"
#include <stdlib.h>

int     check_t(t_file *list)
{
  int   i;

  i = 0;
  while (list->file_name[i] != 0)
    {
      if (list->time > list->next->time)
        return (1);
      if (list->time < list->next->time)
        return (0);
      i++;
    }
  return (0);
}

void    case_t(char *flag, t_file **list)
{
  t_file        *buffer;
  t_file        *start;
  int		i;

  while (flag[i] != 0)
    {
      if (flag[i] == 't')
        {
	  start = *list;
	  buffer = NULL;
	  while (start->next != NULL)
	    {
	      if (check_t(start) == 1)
		{
		  swap(buffer, start, start->next, list);
		  buffer = NULL;
		  start = *list;
		}
	      else
		{
		  buffer = start;
		  start = start->next;
		}
	    }
	}
      i++;
    }
}

void	case_r(char *flag, t_file **list)
{
  t_file	*elem;
  t_file	*buffer;
  t_file	*save;
  int		i;

  i = 0;
  while (flag[i] != 0)
    {
      if (flag[i] == 'r')
	{
	  elem = NULL;
	  buffer = (*list)->next;
	  (*list)->next = elem;
	  while (buffer != NULL)
	    {
	      save = buffer->next;
	      buffer->next = *list;
	      *list = buffer;
	      buffer = save;
	    }
	}
      i++;
    }
}
