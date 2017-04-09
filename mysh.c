/*
** mysh.c for mysh in /home/brunne_s/rendu/PSU_2013_minishell1
** 
** Made by brunner steeven
** Login   <brunne_s@epitech.net>
** 
** Started on  Thu Dec 12 13:43:21 2013 brunner steeven
** Last update Mon Jan  6 17:36:04 2014 brunner steeven
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void     my_putchar(char c)
{
  write(1, &c, 1);
}

int      my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int      my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	s;

  i = 0;
  s = 0;
  while (dest[s] != '\0')
    {
      s = s + 1;
    }
  while (src[i] != '\0')
    {
      dest[s] = src[i];
      i = i + 1;
      s = s + 1;
    }
  dest[s] = '\0';
  return (dest);
}
