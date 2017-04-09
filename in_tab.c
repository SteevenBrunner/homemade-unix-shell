/*
** get_PATH.c for get_PATH in /home/brunne_s/rendu/PSU_2013_minishell1/shell
** 
** Made by brunner steeven
** Login   <brunne_s@epitech.net>
** 
** Started on  Tue Dec 17 13:52:15 2013 brunner steeven
** Last update Mon Jan  6 23:05:34 2014 brunner steeven
*/

#include "struct_get_path.h"
#include "struct_in_tab.h"
#include <stdlib.h>
#include <stdio.h>

void	initialise_struct_path(t_in_tab **lis)
{
  *lis = malloc(sizeof(t_in_tab));
  (*lis)->move_str = 0;
  (*lis)->move_tab = 0;
  (*lis)->move_stock = 0;
  (*lis)->malloc_var = 0;
  (*lis)->size_tracks = 0;
}

void	malloc_tab(char *str, char *str_final, t_get_path *list, t_in_tab *lis)
{
  lis->nb_tracks = count_items(str, list);
  lis->tab_path = malloc(lis->nb_tracks * sizeof(*lis->tab_path));
  while (lis->malloc_var < lis->nb_tracks + 1)
    {
      lis->tab_path[lis->malloc_var] = malloc(lis->nb_tracks * sizeof(**lis->tab_path));
      lis->malloc_var++;
    }
  if (str_final[lis->move_str] != ':')
    {
      while (str_final[lis->move_str] != ':')
        {
          lis->size_tracks++;
          lis->move_str++;
        }
    }
}

void	first_track(char *str, char *str_final, t_get_path *list, t_in_tab *lis)
{
  if (lis->size_tracks > 0)
    {
      lis->stock_tracks = malloc((lis->size_tracks + 1) * sizeof(lis->stock_tracks));
      if (lis->stock_tracks == NULL)
        {
          my_putstr("[Error] : malloc");
          return ;
        }
      while (lis->size_tracks > 0)
        {
          lis->stock_tracks[lis->move_stock] = str_final[lis->move_stock];
          lis->move_stock++;
          lis->size_tracks--;
        }
      lis->stock_tracks[lis->move_stock] = '\0';
      lis->tab_path[lis->move_tab] = lis->stock_tracks;
      lis->move_tab++;
      lis->move_stock = 0;
      lis->size_tracks = 0;
    }
}

void	stock_in_tab(char *str, char *str_final, t_get_path *list, t_in_tab *lis)
{
  if (lis->size_tracks > 0)
    {
      lis->stock_tracks = malloc(lis->size_tracks * sizeof(lis->stock_tracks));
      if (lis->stock_tracks == NULL)
	{
	  my_putstr("[Error] : malloc");
	  return ;
	}
      lis->move_in_tracks = 0;
      while (lis->size_tracks > 0)
	{
	  lis->stock_tracks[lis->move_in_tracks] = str_final[lis->move_stock];
	  lis->move_stock++;
	  lis->move_in_tracks++;
	  lis->size_tracks--;
	}
      lis->stock_tracks[lis->move_in_tracks] = '\0';
      lis->tab_path[lis->move_tab] = lis->stock_tracks;
      lis->move_tab++;
      lis->size_tracks = 0;
    }
}

char	**path_in_tab(char *str, char *str_final, t_get_path *list, t_in_tab *lis)
{
  malloc_tab(str, str_final, list, lis);
  first_track(str, str_final, list, lis); 
  while (str_final[lis->move_str] != '\0')
    {
      if (str_final[lis->move_str - 1] == ':' && str_final[lis->move_str] != ':')
	{
	  lis->move_stock = lis->move_str;
	  while (str_final[lis->move_str] != ':')
	    {
	      lis->size_tracks++;
	      lis->move_str++;
	    }
	  lis->move_str = (lis->move_str + 1) - lis->size_tracks;
	}
      stock_in_tab(str, str_final, list, lis);
      lis->size_tracks = 0;
      lis->move_str++;    
    }
  lis->tab_path[lis->move_tab][0] = '\0';
  my_putstr(lis->tab_path[0]);
  my_putstr("\n");
  return (lis->tab_path);
}
