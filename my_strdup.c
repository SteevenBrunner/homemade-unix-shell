/*
** my_strdup.c for my_strdup.c in /home/brunne_s/rendu/PSU_2013_minishell1
** 
** Made by brunner steeven
** Login   <brunne_s@epitech.net>
** 
** Started on  Thu Jan  2 15:49:01 2014 brunner steeven
** Last update Mon Jan  6 23:15:08 2014 brunner steeven
*/

#include <stdlib.h>
#include <stdio.h>
#include "struct_in_tab.h"

char	*my_strdup(char *src)
{
  char	*str;
  int	i;

  i = 0;
  str = malloc((my_strlen(src) + 1) * sizeof(*src));
  while (src[i] != '\0')
    {
      str[i] = src[i];
      i++;
    }
  str[i] = '\0';
  return (str);
}
