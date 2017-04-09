/*
** struct_path_in_tab.h for struct_path_in_tab.h in /home/brunne_s/rendu/PSU_2013_minishell1/op_shell
** 
** Made by brunner steeven
** Login   <brunne_s@epitech.net>
** 
** Started on  Thu Jan  2 19:17:21 2014 brunner steeven
** Last update Mon Jan  6 23:16:16 2014 brunner steeven
*/

#ifndef STRUCT_IN_TAB_
# define STRUCT_IN_TAB_

typedef struct	s_in_tab
{
  int		move_str;
  int		move_tab;
  int		move_stock;
  int		malloc_var;
  int		nb_tracks;
  int		size_tracks;
  int		move_in_tracks;
  char		*stock_tracks;
  char		**tab_path;
}		t_in_tab;

#endif /* !STRUCT_IN_TAB_ */
