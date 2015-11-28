/*
** case_recursive.c for my_ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Fri Nov 27 22:04:49 2015 Baptiste veyssiere
** Last update Sat Nov 28 17:41:31 2015 Baptiste veyssiere
*/

#include "file_struct.h"
#include <stdlib.h>
#include <unistd.h>

void	directory_filler(char *str, t_file **list)
{
  t_file	*elem;
  int		length;

  length = my_strlen(str);
  elem->file_name = malloc(length);
  my_strcpy(elem->file_name, str);
  elem->next = *list;
  *list = elem;
}

void	recursive_directory(t_file *list, t_file **buffer)
{
  while (list != NULL)
    {
      if (list->rights[0] == 'd' && list->file_name[0] != '.')
	directory_filler(list->file_name, buffer);
      list = list->next;
    }
}

void		recursivity(char *flag, t_file **list)
{
  int		i;
  int		key;
  t_file	*buffer;
  t_file	*file;
  t_length	length;

  i = 0;
  key = 0;
  buffer = NULL;
  file = NULL;
  while(flag[i] != 0)
    {
      if (flag[i] == 'l')
	key = 1;
      i++;
    }
  while (*list != NULL)
    {
      get_directory((*list)->file_name, &file);
      recursive_directory(file, &buffer);
      my_putstr((*list)->file_name);
      my_putstr(":\n");
      if (key == 1)
	{
	  get_the_lengths(file, &length);
	  my_show_list(file, &length, flag);
	}
      else
	my_show_name(file, flag);
      if ((*list)->next != NULL && buffer == NULL)
	my_putstr("\n");
      recursivity(flag, &buffer);
      *list = (*list)->next;
    }
}

void	case_rec_dot(char *flag, t_file **list)
{
  t_file	*buffer;
  int		i;
  int		key;
  t_length	length;

  buffer = NULL;
  key = 0;
  while (flag[i] != 0)
    {
      if (flag[i] == 'l')
	key = 1;
      i++;
    }
  get_directory(".", list);
  recursive_directory(*list, &buffer);
  my_putstr(".:\n");
  if (key == 1)
    {
      get_the_lengths(*list, &length);
      my_show_list(*list, &length, flag);
    }
  else
    my_show_name(*list, flag);
  my_putstr("\n");
  recursivity(flag, &buffer);
}

int	case_recursive(char *flag, t_directory **directory, t_file **list)
{
  if (*directory == NULL)
    case_rec_dot(flag, list);
  else
    {
      case_l_file(*directory, flag);
      exit(0);
    }
  exit(0);
}
