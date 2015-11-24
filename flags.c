/*
** flags.c for my_ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls/flags
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Tue Nov 24 14:15:57 2015 Baptiste veyssiere
** Last update Tue Nov 24 22:10:19 2015 Baptiste veyssiere
*/

#include <stdlib.h>
#include "file_struct.h"
#include <sys/types.h>
#include <dirent.h>

int	fill_flag(char *flags, char letter, int *key)
{
  int	i;

  i = 0;
  while (flags[i] != 0)
    {
      if (flags[i] == letter)
	{
	  *key = 1;
	  return (0);
	}
      i++;
    }
  flags[i] = letter;
  *key = 1;
  return (0);
}

int	if_flags(int *key, char *str, char *flags, int i)
{
  int	j;
  char	*flag_list;

  j = 0;
  *key = 0;
  flag_list = "lRdrt";
  if (str[i] == 0 && i > 1)
    return (0);
  while (j < 5)
    {
      if (str[i] == flag_list[j])
	fill_flag(flags, flag_list[j], key);
      j++;
    }
  if (*key == 0 || str[1] == 0)
    {
      write(2, "Invalid flag\n", 13);
      exit(1);
    }
  i++;
  if_flags(key, str, flags, i);
}

int	if_direct_or_file(int *key, char *str, t_directory **directory)
{
  t_directory	*elem;

  if (opendir(str) == NULL)
    {
      write(2, "Invalid directory\n", 18);
      exit(1);
    }
  else
    {
      elem = malloc(sizeof(*elem));
      elem->adress = str;
      elem->next = *directory;
      *directory = elem;
    }
  return (0);
}

int		flags_and_home_gestion(int ac, char **av, char *flags, t_directory **directory)
{
  int		i;
  int		key;

  i = 1;
  while (i < ac)
    {
      key = 0;
      if (av[i][0] == '-')
	if_flags(&key, av[i], flags, 1);
      else
	if_direct_or_file(&key, av[i], directory);
      i++;
    }
}
