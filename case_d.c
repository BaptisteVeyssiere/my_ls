/*
** case.c for my_ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Nov 25 14:14:55 2015 Baptiste veyssiere
** Last update Thu Nov 26 10:29:16 2015 Baptiste veyssiere
*/

#include "file_struct.h"
#include <unistd.h>
#include <stdlib.h>

void	adress(t_file **list, t_directory *directory)
{
  while (directory != NULL)
    {
      if (directory->adress)
	get_file(directory->adress, list);
      directory = directory->next;
    }
}

void	file(t_file **list, t_directory *directory)
{
  while(directory != NULL)
    {
      if (directory->file)
	get_file(directory->file, list);
      directory = directory->next;
    }
}

void	case_ld(char *flags, t_directory **directory, t_file **list)
{
  t_length	*length;

  if (*directory == NULL)
    {
      get_file(".", list);
      length = malloc(sizeof(*length));
      get_the_lengths(*list, length);
      my_show_list(*list, length);
    }
  else
    {
      adress(list, *directory);
      file(list, *directory);
      length = malloc(sizeof(*length));
      get_the_lengths(*list, length);
      my_sort_alpha(list);
      my_show_list(*list, length);
      free(length);
    }
}

void	dname_filler(t_file **list, t_directory *directory)
{
  t_file	*elem;

  elem = malloc(sizeof(*elem));
  if (directory->adress != NULL)
    {
      elem->file_name = malloc(my_strlen(directory->adress));
      my_strcpy(elem->file_name, directory->adress);
    }
  else if (directory->file != NULL)
    {
      elem->file_name = malloc(my_strlen(directory->file));
      my_strcpy(elem->file_name, directory->file);
    }
  elem->next = *list;
  *list = elem;
}

int	case_d(char *flags, t_directory **directory, t_file **list)
{
  int	i;

  i = 0;
  while (flags[i] != 0)
    {
      if (flags[i] == 'l')
	{
	  case_ld(flags, directory, list);
	  exit(0);
	}
      i++;
    }
  if (*directory == NULL)
    my_putstr(".\n");
  else
    {
      while (*directory != NULL)
	{
	  dname_filler(list, *directory);
	  *directory = (*directory)->next;
	}
      my_sort_alpha(list);
      my_show_name(*list);
    }
  exit(0);
}
