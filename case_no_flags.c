/*
** case_no_flags.c for my_ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Thu Nov 26 16:31:22 2015 Baptiste veyssiere
** Last update Thu Nov 26 17:32:09 2015 Baptiste veyssiere
*/

#include <stdlib.h>
#include "file_struct.h"

void    case_file(t_directory *directory)
{
  t_file        *file;
  int           key;

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
  my_show_name(file);
  if (key == 1)
    my_putstr("\n");
}

void    case_adress(t_directory *directory, t_file **list)
{
  t_file        *file;

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
      my_putstr(":\n");
      get_directory(file->file_name, list);
      my_sort_alpha(list);
      my_show_name(*list);
      if (file->next != NULL)
        my_putstr("\n");
      while (*list != NULL)
        *list = (*list)->next;
      file = file->next;
    }
}

void	case_no_flags(char *flag, t_file **list, t_directory *directory)
{
  t_length	*length;

  if (directory == NULL)
    {
      get_directory(".", list);
      my_sort_alpha(list);
      my_show_name(*list);
    }
  else
    {
      case_file(directory);
      case_adress(directory, list);
    }
  exit(0);
}
