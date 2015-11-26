/*
** information.c for my_ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Nov 25 15:37:16 2015 Baptiste veyssiere
** Last update Thu Nov 26 15:48:24 2015 Baptiste veyssiere
*/

#include <stdlib.h>
#include "file_struct.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>

void		get_file(char *str, t_file **list)
{
  struct stat   buf;
  struct passwd *uid;
  struct group  *gid;
  t_file        *file;

  file = malloc(sizeof(*file));
  stat(str, &buf);
  uid = getpwuid(buf.st_uid);
  gid = getgrgid(buf.st_gid);
  permissions(buf, file);
  file->hardlink = buf.st_nlink;
  file->size = buf.st_size;
  file->user_name = uid->pw_name;
  file->group_name = gid->gr_name;
  date(file, buf);
  file->file_name = str;
  file->block = buf.st_blocks;
  file->next = *list;
  *list = file;
}

void            get_file_directory(char *str, t_file **list, char *name)
{
  struct stat   buf;
  struct passwd *uid;
  struct group  *gid;
  t_file        *file;

  file = malloc(sizeof(*file));
  stat(str, &buf);
  uid = getpwuid(buf.st_uid);
  gid = getgrgid(buf.st_gid);
  permissions(buf, file);
  file->hardlink = buf.st_nlink;
  file->size = buf.st_size;
  file->user_name = uid->pw_name;
  file->group_name = gid->gr_name;
  date(file, buf);
  file->file_name = malloc(my_strlen(name));
  my_strcpy(file->file_name, name);
  file->block = buf.st_blocks;
  //my_putstr(my_put_nbr(file->block));
  file->next = *list;
  *list = file;
}

void		get_directory(char *str, t_file **list)
{
  DIR		*dir;
  struct dirent	*pathname;
  char		*name;
  char		*assemblage;

  dir = opendir(str);
  while ((pathname = readdir(dir)) != NULL)
    {
      name = malloc(my_strlen(pathname->d_name));
      my_strcpy(name, pathname->d_name);
      assemblage = malloc(my_strlen(str) + my_strlen(name));
      name_assembler(str, name, assemblage);
      get_file_directory(assemblage, list, name);
      //free(name);
      //free(assemblage);
    }
  closedir(dir);
}
