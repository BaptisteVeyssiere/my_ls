/*
** my_strlen.c for my_strlen in /home/VEYSSI_B/rendu/Piscine_C_J04
** 
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
** 
** Started on  Thu Oct  1 18:31:00 2015 Baptiste veyssiere
** Last update Thu Oct  1 20:58:06 2015 Baptiste veyssiere
*/

int	my_strlen(char *str)
{
  int	n;

  n = 0;
  while (*str != 0)
    {
      n++;
      str++;
    }
  return (n);
}
