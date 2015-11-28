/*
** sort.c for my_ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Tue Nov 24 17:43:25 2015 Baptiste veyssiere
** Last update Sat Nov 28 15:18:42 2015 Baptiste veyssiere
*/

#include "file_struct.h"
#include "prototypes.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

get_the_lengths(t_file *list, t_length *lengths)
{
  lengths->hardlink = my_strlen(my_put_nbr(list->hardlink));
  lengths->size = my_strlen(my_put_nbr(list->size));
  lengths->user = my_strlen(list->user_name);
  lengths->group = my_strlen(list->group_name);
  list = list->next;
  while (list != NULL)
    {
      lengths->hardlink =
	LENGTH(lengths->hardlink, my_strlen(my_put_nbr(list->hardlink)));
      lengths->size = LENGTH(lengths->size, my_strlen(my_put_nbr(list->size)));
      lengths->user = LENGTH(lengths->user, my_strlen(list->user_name));
      lengths->group = LENGTH(lengths->group, my_strlen(list->group_name));
      list = list->next;
    }
}

int	check(t_file *list)
{
  int	i;

  i = 0;
  while (list->file_name[i] != 0)
    {
      if (list->file_name[i] > list->next->file_name[i])
	return (1);
      if (list->file_name[i] < list->next->file_name[i])
	return (0);
      i++;
    }
  return (0);
}

void	swap(t_file *buffer, t_file *start, t_file *next,  t_file **list)
{
  t_file	*tmp;

  if (buffer == NULL)
    {
      *list = next;
    }
  else
    buffer->next = next;
  tmp = next->next;
  next->next = start;
  start->next = tmp;
}

void	my_sort_alpha(t_file **list)
{
  t_file	*buffer;
  t_file	*start;

  start = *list;
  buffer = NULL;
  while (start->next != NULL)
    {
      if (check(start) == 1)
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
