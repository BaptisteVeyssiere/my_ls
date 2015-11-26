/*
** my_ls.c for ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Nov 23 10:43:56 2015 Baptiste veyssiere
** Last update Thu Nov 26 18:12:58 2015 Baptiste veyssiere
*/

#include <unistd.h>
#include <stdlib.h>
#include "prototypes.h"
#include "file_struct.h"

void		main(int ac, char **av)
{
  char          *flags;
  t_directory   *directory;

  flags = malloc(7);
  directory = NULL;
  flags_and_home_gestion(ac, av, flags, &directory);
  displayer(flags, &directory);
}
