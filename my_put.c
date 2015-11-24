/*
** my_put.c for my_ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Tue Nov 24 16:10:23 2015 Baptiste veyssiere
** Last update Tue Nov 24 16:11:38 2015 Baptiste veyssiere
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *s)
{
  while (*s != 0)
    my_putchar(*s++);
}
