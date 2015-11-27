/*
** case_r_up.c for my_ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Fri Nov 27 14:16:05 2015 Baptiste veyssiere
** Last update Fri Nov 27 14:30:08 2015 Baptiste veyssiere
*/

#include <unistd.h>
#include "file_struct.h"

void	case_r_up(t_file **list, char *flag)
{
  int		i;
  t_file	*file;

  i = 0;
  file = NULL;
  while (flag[i] != 0)
    {
      if (flag[i] == 'R')
	{
	  my_sort_alpha(list, flag);
	  while (*list != NULL)
	    {
	      get_directory((*list)->file_name, &file);
	      my_sort_alpha(&file);
	      my_show_list(file, flag);
	      *list = (*list)->next;
	    }
	}
      i++;
    }
}
