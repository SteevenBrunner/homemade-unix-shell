##
## Makefile for Makefile in /home/brunne_s/rendu/PSU_2013_minishell1/op_shell
## 
## Made by brunner steeven
## Login   <brunne_s@epitech.net>
## 
## Started on  Mon Jan  6 13:24:38 2014 brunner steeven
## Last update Mon Jan  6 23:20:12 2014 brunner steeven
##

Name = mysh

RM = rm -f

SRC = mysh.c \
      in_tab.c \
      get_path.c \
      my_strdup.c \

OBJ =	$(SRC:.c=.o)

all:
	cc $(SRC) -o $(Name) 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)  
