/*
** my_ls.c for ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Nov 23 10:43:56 2015 Baptiste veyssiere
** Last update Sun Nov 29 20:02:43 2015 Baptiste veyssiere
*/

#include <unistd.h>
#include <stdlib.h>
#include "file_struct.h"

void	free_function(t_file *list)
{
  t_file	*tmp;

  while (list != NULL)
    {
      tmp = list;
      list = list->next;
      if (tmp->date != NULL)
	free(tmp->date);
      if (tmp->user_name != NULL)
	free(tmp->user_name);
      if (tmp->group_name != NULL)
	free(tmp->group_name);
      if (tmp->file_name != NULL)
	free(tmp->file_name);
      free(tmp);
    }
}

int	displayer(char *flags, t_directory **directory)
{
  int           i;
  t_file        *list;

  i = 0;
  list = NULL;
  while (flags[i] != 0 && flags[i] != 'l' && flags[i] != 'R' && flags[i] != 'd')
    i++;
  if (flags[i] == 0)
    case_no_flags(flags, &list, *directory);
  i = 0;
  while (flags[i] != 0)
    if (flags[i++] == 'd')
      case_d(flags, directory, &list);
  i = 0;
  while (flags[i] != 0)
    if (flags[i++] == 'R')
      case_recursive(flags, directory, &list);
  i = 0;
  while (flags[i] != 0)
    if (flags[i++] == 'l')
      case_l(flags, directory, &list);
  free_function(list);
  exit(0);
}

void		main(int ac, char **av)
{
  char          *flags;
  t_directory   *directory;
  t_directory	*file;
  int		i;

  flags = malloc(7);
  directory = NULL;
  flags_and_home_gestion(ac, av, flags, &directory);
  displayer(flags, &directory);
  free(flags);
  while (directory != NULL)
    {
      file = directory;
      directory = directory->next;
      if (file->adress != NULL)
	free(file->adress);
      else
	free(file->file);
      free(file);
    }
}
