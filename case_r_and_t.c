/*
** case_r_and_t.c for my_ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Thu Nov 26 17:44:27 2015 Baptiste veyssiere
** Last update Thu Nov 26 19:00:30 2015 Baptiste veyssiere
*/

#include "file_struct.h"
#include <stdlib.h>

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
