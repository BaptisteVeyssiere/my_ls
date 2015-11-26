/*
** my_ls.c for ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Nov 23 10:43:56 2015 Baptiste veyssiere
** Last update Thu Nov 26 01:55:19 2015 Baptiste veyssiere
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <stdlib.h>
#include "prototypes.h"
#include "file_struct.h"

void		main(int ac, char **av)
{
  DIR		*dir;
  struct dirent	*pathname;
  t_file	*list;
  char          *flags;
  t_directory   *directory;

  //dir = opendir(".");
  list = NULL;
  flags = malloc(6);
  directory = NULL;
  /*while ((pathname = readdir(dir)) != NULL)
    my_ls(pathname, &list);
    my_sort_alpha(&list);*/
  flags_and_home_gestion(ac, av, flags, &directory);
  displayer(flags, &directory, &list);
  //closedir(dir);
}
