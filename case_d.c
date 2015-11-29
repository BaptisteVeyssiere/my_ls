/*
** case.c for my_ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Nov 25 14:14:55 2015 Baptiste veyssiere
** Last update Sun Nov 29 15:51:56 2015 Baptiste veyssiere
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
  while (directory != NULL)
    {
      if (directory->file)
	get_file(directory->file, list);
      directory = directory->next;
    }
}

void	case_ld(char *flag, t_directory **directory, t_file **list)
{
  t_length	*length;

  if (*directory == NULL)
    {
      get_file(".", list);
      length = malloc(sizeof(*length));
      get_the_lengths(*list, length);
      my_show_hidden_list(*list, length, flag);
    }
  else
    {
      adress(list, *directory);
      file(list, *directory);
      length = malloc(sizeof(*length));
      get_the_lengths(*list, length);
      my_sort_alpha(list);
      my_show_hidden_list(*list, length, flag);
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

int	case_d(char *flag, t_directory **directory, t_file **list)
{
  int	i;

  i = 0;
  while (flag[i] != 0)
    {
      if (flag[i] == 'l')
	{
	  case_ld(flag, directory, list);
	  exit(0);
	}
      i++;
    }
  if (*directory == NULL && flag[5] != '0')
    my_putstr(".\n");
  else if (*directory != NULL)
    {
      while (*directory != NULL)
	{
	  dname_filler(list, *directory);
	  *directory = (*directory)->next;
	}
      my_sort_alpha(list);
      my_show_hidden_name(*list, flag);
    }
  exit(0);
}
