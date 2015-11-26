/*
** case_l.c for my_ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Nov 25 16:30:41 2015 Baptiste veyssiere
** Last update Thu Nov 26 19:05:32 2015 Baptiste veyssiere
*/

#include "file_struct.h"
#include <unistd.h>
#include <stdlib.h>

void	case_l_file(t_directory *directory, char *flag)
{
  t_length	*length;
  t_file	*file;
  int		key;

  file = NULL;
  key = 0;
  while (directory != NULL)
    {
      if (directory->file != NULL)
	get_file(directory->file, &file);
      if (directory->adress != NULL)
	key = 1;
      directory = directory->next;
    }
  my_sort_alpha(&file);
  length = malloc(sizeof(*length));
  get_the_lengths(file, length);
  my_show_hidden_list(file, length);
  if (key == 1)
    my_putstr("\n");
}

void	add_adress(t_file **file, char *str)
{
  t_file	*elem;

  elem = malloc(sizeof(*elem));
  elem->file_name = malloc(my_strlen(str));
  my_strcpy(elem->file_name, str);
  elem->next = *file;
  *file = elem;
}

void	case_l_adress(t_directory *directory, t_file **list, char *flag)
{
  t_file	*length;
  t_file	*file;

  file = NULL;
  while (directory != NULL)
    {
      if (directory->adress != NULL)
	add_adress(&file, directory->adress);
      directory = directory->next;
    }
  if (file != NULL)
    my_sort_alpha(&file);
  while (file != NULL)
    {
      my_putstr(file->file_name);
      my_putstr(":\ntotal ");
      get_directory(file->file_name, list);
      my_sort_alpha(list);
      length = malloc(sizeof(*length));
      get_the_lengths(*list, length);
      my_putstr(my_put_nbr(total_block(*list)));
      my_putstr("\n");
      my_show_list(*list, length);
      if (file->next != NULL)
	my_putstr("\n");
      free(length);
      while (*list != NULL)
	*list = (*list)->next;
      file = file->next;
    }
}

int	case_l(char *flags, t_directory **directory, t_file **list)
{
  t_length	*length;

  if (*directory == NULL && flags[5] != '0')
    {
      get_directory(".", list);
      my_sort_alpha(list);
      length = malloc(sizeof(*length));
      get_the_lengths(*list, length);
      my_putstr("total ");
      my_putstr(my_put_nbr(total_block(*list)));
      my_putstr("\n");
      my_show_list(*list, length);
    }
  else
    {
      case_l_file(*directory, flags);
      case_l_adress(*directory, list, flags);
    }
  exit (0);
}
