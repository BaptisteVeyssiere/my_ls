/*
** my_strcpy.c for my_strcpy in /home/VEYSSI_B/rendu/Piscine_C_J06
** 
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
** 
** Started on  Mon Oct  5 09:56:35 2015 Baptiste veyssiere
** Last update Thu Oct 22 22:23:38 2015 Baptiste veyssiere
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (i < my_strlen(src))
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}
