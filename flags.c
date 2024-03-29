/*
** flags.c for my_ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls/flags
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Tue Nov 24 14:15:57 2015 Baptiste veyssiere
** Last update Fri Nov 27 22:03:34 2015 Baptiste veyssiere
*/

#include <stdlib.h>
#include "file_struct.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

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
      write(2, "my_ls: invalid option -- '", 26);
      write(2, &str[i], 1);
      write(2, "'\n", 2);
      exit(1);
    }
  i++;
  if_flags(key, str, flags, i);
}

void		if_file(char *str, t_directory **directory, char *flag)
{
  t_directory	*elem;
  struct stat	buf;

  if (stat(str, &buf) == -1)
    {
      write(2, "my_ls: cannot access ", 21);
      write(2, str, my_strlen(str));
      write(2, ": No such file or directory\n", 28);
      flag[5] = '0';
    }
  else
    {
      elem = malloc(sizeof(*elem));
      elem->file = str;
      elem->next = *directory;
      *directory = elem;
    }
}

int		if_direct_or_file(int *key, char *str, t_directory **directory,
				  char *flag)
{
  t_directory	*elem;
  char		*buffer;
  struct stat   buf;

  if (opendir(str) == NULL)
    if_file(str, directory, flag);
  else
    {
      elem = malloc(sizeof(*elem));
      elem->adress = str;
      elem->next = *directory;
      *directory = elem;
    }
  return (0);
}

int		flags_and_home_gestion(int ac, char **av, char *flags,
				       t_directory **directory)
{
  int		i;
  int		key;

  i = 1;
  while (i < ac)
    {
      key = 0;
      if (av[i][0] == '-' && av[i][1] != 0)
	if_flags(&key, av[i], flags, 1);
      else
	if_direct_or_file(&key, av[i], directory, flags);
      i++;
    }
}
