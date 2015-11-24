/*
** my_ls.c for ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Nov 23 10:43:56 2015 Baptiste veyssiere
** Last update Tue Nov 24 23:32:54 2015 Baptiste veyssiere
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
#include <stdio.h>

void	permissions(struct stat buf, t_file *file)
{
  file->rights[0] = ((S_ISDIR(buf.st_mode)) ? 'd' : '-');
  file->rights[1] = ((buf.st_mode & S_IRUSR) ? 'r' : '-');
  file->rights[2] = ((buf.st_mode & S_IWUSR) ? 'w' : '-');
  file->rights[3] = ((buf.st_mode & S_IXUSR) ? 'x' : '-');
  file->rights[4] = ((buf.st_mode & S_IRGRP) ? 'r' : '-');
  file->rights[5] = ((buf.st_mode & S_IWGRP) ? 'w' : '-');
  file->rights[6] = ((buf.st_mode & S_IXGRP) ? 'x' : '-');
  file->rights[7] = ((buf.st_mode & S_IROTH) ? 'r' : '-');
  file->rights[8] = ((buf.st_mode & S_IWOTH) ? 'w' : '-');
  file->rights[9] = ((buf.st_mode & S_IXOTH) ? 'x' : '-');
  file->rights[10] = 0;
}

void	date(t_file *file, struct stat buf)
{
  file->date = malloc(25);
  my_strcpy(file->date, ctime(&buf.st_mtime));
  file->date += 4;
  file->date[12] = 0;
}

void	my_put_name(t_file *file, struct dirent *pathname)
{
  int	i;

  i = 0;
  file->file_name = malloc(my_strlen(pathname->d_name));
  while (pathname->d_name[i] != 0)
    {
      file->file_name[i] = pathname->d_name[i];
      i++;
    }
  file->file_name[i] = 0;
}

void	my_ls(struct dirent *pathname, t_file **list)
{
  struct stat   buf;
  struct passwd *uid;
  struct group  *gid;
  t_file	*file;

  file = malloc(sizeof(*file));
  stat(pathname->d_name, &buf);
  uid = getpwuid(buf.st_uid);
  gid = getgrgid(buf.st_gid);
  permissions(buf, file);
  file->hardlink = buf.st_nlink;
  file->size = buf.st_size;
  file->user_name = uid->pw_name;
  file->group_name = gid->gr_name;
  date(file, buf);
  my_put_name(file, pathname);
  file->next = *list;
  *list = file;
}

void	my_show_list(t_file *list)
{
  while (list != NULL)
    {
      printf("%s %i %s %s %d %s %s\n", list->rights, list->hardlink, list->user_name, list->group_name, list->size, list->date, list->file_name);
      list = list->next;
    }
}

void		main(int ac, char **av)
{
  DIR		*dir;
  struct dirent	*pathname;
  t_file	*list;
  char          *flags;
  t_directory   *directory;

  dir = opendir(".");
  list = NULL;
  flags = malloc(6);
  directory = NULL;
  while ((pathname = readdir(dir)) != NULL)
    my_ls(pathname, &list);
  my_sort_alpha(&list);
  flags_and_home_gestion(ac, av, flags, &directory);
  closedir(dir);
}
