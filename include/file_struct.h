/*
** file_struct.h for ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Nov 23 15:25:25 2015 Baptiste veyssiere
** Last update Thu Nov 26 18:01:36 2015 Baptiste veyssiere
*/

#ifndef FILE_STRUCT_H
# define FILE_STRUCT_H

typedef struct s_file
{
  char  rights[11];
  int   hardlink;
  int   size;
  char  *date;
  char  *user_name;
  char  *group_name;
  char  *file_name;
  int	block;
  int	time;
  struct s_file	*next;
} t_file;

typedef struct s_directory
{
  char	*adress;
  char	*file;
  struct s_directory *next;
}t_directory;

typedef struct
{
  int	hardlink;
  int	size;
  int	user;
  int	group;
}t_length;

#endif /* !FILE_STRUCT_H */
