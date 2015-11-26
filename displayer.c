/*
** displayer.c for my_ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Thu Nov 26 01:31:48 2015 Baptiste veyssiere
** Last update Thu Nov 26 16:19:03 2015 Baptiste veyssiere
*/

#include <stdlib.h>
#include "file_struct.h"

int             displayer(char *flags, t_directory **directory)
{
  int           i;
  t_file	*list;

  i = 0;
  list = NULL;
  while (flags[i] != 0)
    {
      if (flags[i] == 'd')
	case_d(flags, directory, &list);
      i++;
    }
  i = 0;
  while (flags[i] != 0)
    {
      if (flags[i] == 'l')
	case_l(flags, directory, &list);
      i++;
    }
  return (0);
}

void    my_show_hidden_list(t_file *list, t_length *length)
{
  int   max;

  while (list != NULL)
    {
      my_putstr(list->rights);
      my_putstr(" ");
      max = my_strlen(my_put_nbr(list->hardlink));
      while (max++ < length->hardlink)
        my_putstr(" ");
      my_putstr(my_put_nbr(list->hardlink));
      my_putstr(" ");
      max = my_strlen(list->user_name);
      while (max++ < length->user)
        my_putstr(" ");
      my_putstr(list->user_name);
      my_putstr(" ");
      max = my_strlen(list->group_name);
      while (max++ < length->group)
        my_putstr(" ");
      my_putstr(list->group_name);
      my_putstr(" ");
      max = my_strlen(my_put_nbr(list->size));
      while (max++ < length->size)
        my_putstr(" ");
      my_putstr(my_put_nbr(list->size));
      my_putstr(" ");
      my_putstr(list->date);
      my_putstr(" ");
      my_putstr(list->file_name);
      my_putstr("\n");
      list = list->next;
    }
}

void    my_show_list(t_file *list, t_length *length)
{
  int	max;

  while (list != NULL)
    {
      if (list->file_name[0] == '.')
	list = list->next;
      else
	{
	  my_putstr(list->rights);
	  my_putstr(" ");
	  max = my_strlen(my_put_nbr(list->hardlink));
	  while (max++ < length->hardlink)
	    my_putstr(" ");
	  my_putstr(my_put_nbr(list->hardlink));
	  my_putstr(" ");
	  max = my_strlen(list->user_name);
	  while (max++ < length->user)
	    my_putstr(" ");
	  my_putstr(list->user_name);
	  my_putstr(" ");
	  max = my_strlen(list->group_name);
	  while (max++ < length->group)
	    my_putstr(" ");
	  my_putstr(list->group_name);
	  my_putstr(" ");
	  max = my_strlen(my_put_nbr(list->size));
	  while (max++ < length->size)
	    my_putstr(" ");
	  my_putstr(my_put_nbr(list->size));
	  my_putstr(" ");
	  my_putstr(list->date);
	  my_putstr(" ");
	  my_putstr(list->file_name);
	  my_putstr("\n");
	  list = list->next;
	}
    }
}

void	my_show_name(t_file *list)
{
  while (list != NULL)
    {
      my_putstr(list->file_name);
      if (list->next != NULL)
	my_putstr("  ");
      else
	my_putstr("\n");
      list = list->next;
    }
}
