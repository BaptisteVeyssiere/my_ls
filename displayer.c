/*
** displayer.c for my_ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Thu Nov 26 01:31:48 2015 Baptiste veyssiere
** Last update Sun Nov 29 16:01:45 2015 Baptiste veyssiere
*/

#include <stdlib.h>
#include "file_struct.h"

void	spaces(t_length *length, t_file *list)
{
  int	max;

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
}

void	my_show_hidden_list(t_file *list, t_length *length, char *flag)
{
  int   max;

  case_t(flag, &list);
  case_r(flag, &list);
  while (list != NULL)
    {
      my_putstr(list->rights);
      my_putstr(" ");
      spaces(length, list);
      my_putstr(my_put_nbr(list->size));
      my_putstr(" ");
      my_putstr(list->date);
      my_putstr(" ");
      my_putstr(list->file_name);
      my_putstr("\n");
      list = list->next;
    }
}

void	my_show_list(t_file *list, t_length *length, char *flag)
{
  int	max;

  case_t(flag, &list);
  case_r(flag, &list);
  while (list != NULL)
    {
      if (list->file_name[0] == '.')
	list = list->next;
      else
	{
	  my_putstr(list->rights);
	  my_putstr(" ");
	  spaces(length, list);
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

void	my_show_hidden_name(t_file *list, char *flag)
{
  case_t(flag, &list);
  case_r(flag, &list);
  while (list != NULL)
    {
      my_putstr(list->file_name);
      my_putstr("\n");
      list = list->next;
    }
}

void	my_show_name(t_file *list, char *flag)
{
  case_t(flag, &list);
  case_r(flag, &list);
  while (list != NULL)
    {
      if (list->file_name[0] != '.')
	{
	  my_putstr(list->file_name);
	  my_putstr("\n");
	}
      list = list->next;
    }
}
