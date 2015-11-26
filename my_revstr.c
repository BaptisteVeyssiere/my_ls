/*
** my_revstr.c for my_revstr in /home/VEYSSI_B/rendu/Piscine_C_J06/ex_04
** 
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
** 
** Started on  Mon Oct  5 11:43:03 2015 Baptiste veyssiere
** Last update Mon Oct  5 11:55:54 2015 Baptiste veyssiere
*/

char	*my_revstr(char *str)
{
  int	i;
  int	j;
  char	swap[60];

  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      swap[i] = str[i];
      i++;
    }
  i--;
  while (swap[i] != 0)
    {
      str[i] = swap[j];
      i--;
      j++;
    }
  return (str);
}
