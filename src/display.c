/*
** display.c for  in /home/maison_f/Epitech/rendu/CPE_2015_BSQ
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Sun Dec 20 22:13:24 2015 Maisonnave Florian
** Last update Mon Dec 21 19:02:25 2015 Maisonnave Florian
*/

#include "struct.h"

int	error(int ac, char **av, int test)
{
  int	fd;

  if (ac != 2)
    {
      my_putstr("Error file.\n");
      return (1);
    }
  if (fd = open(av[1], O_RDONLY) < 0)
    {
      my_putstr("Error file.\n");
      return (1);
    }
  return (0);
}

void	display_id(t_list *s)
{
  int	y;
  int	x;

  y = 0;
  x = 0;
  while (y < s->nb_lines)
    {
      my_putstr(s->tab[y]);
      y++;
    }
}

int	test_o(t_list *s)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (y < s->nb_lines)
    {
      while (s->tab[y][x] != '\0')
	{
	  if (s->tab[y][x] == 'o')
	    x++;
	  else
	    return (1);
	}
      x = 0;
      y++;
    }
  return (0);
}

void	in_check(t_list *s)
{
  s->cmp_y++;
  s->cmp_x = 0;
}

void	display(t_list *s)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (y < s->nb_lines)
    {
      while (x < s->nb_colons)
	{
	  if (y >= s->pos_def_y && y < (s->pos_def_y + s->size_def))
	    {
	      if (x >= s->pos_def_x && x < (s->pos_def_x + s->size_def))
	      {
		if (s->tab[y][x] != '\n')
		  {
		    s->tab[y][x] = 'x';
		  }
	      }
	    }
	  my_putchar(s->tab[y][x]);
	  x++;
	}
      y++;
      x = 0;
    }
}
