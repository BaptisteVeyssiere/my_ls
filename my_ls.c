/*
** my_ls.c for ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Nov 23 10:43:56 2015 Baptiste veyssiere
** Last update Fri Nov 27 22:08:05 2015 Baptiste veyssiere
*/

#include <unistd.h>
#include <stdlib.h>
#include "file_struct.h"

int	displayer(char *flags, t_directory **directory)
{
  int           i;
  t_file        *list;

  i = 0;
  list = NULL;
  while (flags[i] != 0)
    {
      if (flags[i] == 'R')
	case_recursive(flags, directory, &list);
      i++;
    }
  i = 0;
  while (flags[i] != 0 && flags[i] != 'l' && flags[i] != 'R' && flags[i] != 'd')
    i++;
  if (flags[i] == 0)
    case_no_flags(flags, &list, *directory);
  i = 0;
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

void		main(int ac, char **av)
{
  char          *flags;
  t_directory   *directory;

  flags = malloc(7);
  directory = NULL;
  flags_and_home_gestion(ac, av, flags, &directory);
  displayer(flags, &directory);
}
