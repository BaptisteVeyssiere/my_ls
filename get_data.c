/*
** get_data.c for my_ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Thu Nov 26 02:26:42 2015 Baptiste veyssiere
** Last update Thu Nov 26 16:25:24 2015 Baptiste veyssiere
*/

#include "file_struct.h"
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int	total_block(t_file *file)
{
  int	total;

  total = 0;
  while (file != NULL)
    {
      if (file->file_name[0] != '.')
	total += file->block;
      file = file->next;
    }
  total /= 2;
  return (total);
}

void	name_assembler(char *str, char *name, char *assemblage)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  my_strcpy(assemblage, str);
  while (assemblage[i] != 0)
    i++;
  if (assemblage[i - 1] != '/')
    assemblage[i++] = '/';
  while (name[j] != 0)
    assemblage[i++] = name[j++];
  assemblage[i] = 0;
}

void    permissions(struct stat buf, t_file *file)
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

void    date(t_file *file, struct stat buf)
{
  file->date = malloc(my_strlen(ctime(&buf.st_mtime)));
  my_strcpy(file->date, ctime(&buf.st_mtime));
  file->date += 4;
  file->date[12] = 0;
}

void    my_put_name(t_file *file, struct dirent *pathname)
{
  int   i;

  i = 0;
  file->file_name = malloc(my_strlen(pathname->d_name));
  while (pathname->d_name[i] != 0)
    {
      file->file_name[i] = pathname->d_name[i];
      i++;
    }
  file->file_name[i] = 0;
}
