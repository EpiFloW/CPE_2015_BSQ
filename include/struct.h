/*
** stuct.h for  in /home/maison_f/Epitech/rendu/CPE_2015_BSQ
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Tue Dec 15 18:43:49 2015 Maisonnave Florian
** Last update Mon Dec 21 18:33:22 2015 Maisonnave Florian
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_list
{
  char		**tab;
  int		nb_colons;
  int		pos_tempo_x;
  int		pos_tempo_y;
  int		pos_def_x;
  int		pos_def_y;
  int		size_tempo;
  int		size_def;
  int		nb_lines;
  int		size;
  int		cmp_x;
  int		cmp_y;
}		t_list;

void	my_putchar(char);
void	my_putstr(char *);
void	my_putnbr(int);
int	my_getnbr(char *);
void	create_tab(t_list *, char *);
void	algorithm(t_list *);
int	check(t_list *, int, int);
void	display(t_list *);
void	init(t_list *);
void	init_x_y(t_list *);
int	calc(t_list *, int);
void	free_tab(t_list *);
void	in_check(t_list *);
int	test_o(t_list *);
void	display_id(t_list *);
int	error(int, char **, int);

#endif
