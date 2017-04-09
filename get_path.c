/*
** get_PATH.c for get_PATH in /home/brunne_s/rendu/PSU_2013_minishell1/shell
** 
** Made by brunner steeven
** Login   <brunne_s@epitech.net>
** 
** Started on  Tue Dec 17 13:52:15 2013 brunner steeven
** Last update Mon Jan  6 23:08:36 2014 brunner steeven
*/

#include "struct_get_path.h"
#include "struct_in_tab.h"
#include <stdlib.h>
#include <stdio.h>

void	capture_path(char *str, t_get_path *list)
{
  list->move_str = 0;
  list->size_path = 0;
  while (str[list->move_str] != '\0')
    {
      if (str[list->move_str] == 'P' && str[list->move_str + 1] == 'A' &&
          str[list->move_str + 2] == 'T' && str[list->move_str + 3] == 'H')
        {
          list->move_str = list->move_str + 5;
	  list->move_save = list->move_str;
	 while (str[list->move_str] != '\0')
            {
              list->move_str++;
              list->size_path++;
            }
          list->move_str--;
        }
      list->move_str++;
    }
  list->move_str = 0;
  list->path = malloc(list->size_path * sizeof(*list->path));
}

char	*get_path(char *str, t_get_path *list)
{
  list = malloc(sizeof(t_get_path));
  capture_path(str, list);
  if (list->path == NULL)
    {
      my_putstr("[Error] : malloc");
    }     
  while (str[list->move_save] != '\0')
    {
      while (str[list->move_save] != '\0')
	{
	  list->path[list->move_str] = str[list->move_save];
	  list->move_str++;
	  list->move_save++;
	}
    }
  list->path[list->move_str] = '\0';
  return (list->path);
}

int	count_items(char *str, t_get_path *list)
{
  int	i;
  int	nb;
  char	*str_final;

  i = 0;
  nb = 1;
  str_final = get_path(str, list);
  while (str_final[i] != '\0')
    {
      while (str_final[i] != ':' && str_final[i] != '\0')
	i++;
      if (str_final[i] == ':')
	{
	  nb++;
	  i++;
	}
    }
  return (nb);
}

int	main(int argc, char **argv, char **env)
{
  t_get_path	*list;
  t_in_tab	*lis;
  char		*str;
  char		buff[200];
  char		*str_final;
  int		i;
  int		val_execve;
  int		move_execve;
  char		*str_shell;
  char		*str_search;

  while (*env != 0)
    {
      if (env[0][0] == 'P' && env[0][1] == 'A' &&
          env[0][2] == 'T' && env[0][3] == 'H')
        str = my_strdup(*env);
      env++;
    }
  get_path(str, list);
  str_final = get_path(str, list);
  initialise_struct_path(&lis);
  path_in_tab(str, str_final, list, lis);
  str_shell = argv[1];
  val_execve = 0;
  move_execve = 0;
  while (42)
    {
      my_putstr("$>");
      i = read(0, buff, 200);
      buff[i - 1] = '\0';
      if (i == -1)
	my_putstr("[Error] : read\n");
      if (i != 1 && i != -1)
        {
          str_shell = malloc(i * sizeof(*str_shell));
          while (val_execve == 0 && move_execve < lis->move_tab)
	    {
              str_search = malloc((my_strlen(buff) +
                                   my_strlen(lis->tab_path[move_execve] + 1)) * sizeof(str_search));
              my_strcat(str_search, lis->tab_path[move_execve]);
              str_search[my_strlen(lis->tab_path[move_execve])] = '/';
              my_strcat(str_search, buff);
              if (execve(str_search, argv, env) == -1)
		move_execve++;
              else
                val_execve = 1;
            }
        }
    }
  return (0);
}
