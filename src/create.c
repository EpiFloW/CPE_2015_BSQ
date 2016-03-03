/*
** create.c for  in /home/maison_f/Epitech/rendu/CPE_2015_BSQ
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Sun Dec 20 22:13:05 2015 Maisonnave Florian
** Last update Tue Jan 19 19:41:54 2016 Maisonnave Florian
*/

#include "struct.h"

void	init(t_list *s)
{
  s->pos_tempo_x = 0;
  s->pos_tempo_y = 0;
  s->pos_def_x = 0;
  s->pos_def_y = 0;
  s->size_tempo = 0;
  s->size_def = 0;
  s->cmp_x = 0;
  s->cmp_y = 0;
}

void	init_x_y(t_list *s)
{
  s->cmp_x = 0;
  s->cmp_y = 0;
}

int	check(t_list *s, int px, int py)
{
  init_x_y(s);
  if ((px + s->size_tempo) < s->nb_colons)
    {
      if ((py + s->size_tempo) < s->nb_lines)
	{
	  while (s->cmp_y < s->size_tempo)
	    {
	      while (s->cmp_x < s->size_tempo)
		{
		  if (s->tab[py][px] == 'o')
		    return (1);
		  s->cmp_x++;
		  px++;
		}
	      in_check(s);
	      px = px - s->size_tempo;
	      py++;
	    }
	}
      else
	return (1);
    }
  else
    return (1);
  return (0);
}

void	algorithm(t_list *s)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  init(s);
  while ((y + s->size_tempo) < s->nb_lines)
    {
      while ((x + s->size_tempo) < s->nb_colons)
	{
	  while (check(s, x, y) == 0)
	    {
	      if (s->size_tempo > s->size_def)
		{
		  s->size_def = s->size_tempo;
		  s->pos_def_x = x;
		  s->pos_def_y = y;
		}
	      s->size_tempo++;
	    }
	  x++;
	}
      y++;
      x = 0;
    }
}

  void	create_tab(t_list *s, char *av1)
{
  char	c;
  int	fd;
  int	ret;
  int	x;
  int	y;

  x = 0;
  y = 0;
  fd = open(av1, O_RDONLY);
  while ((ret = read(fd, &c, 1)) > 0)
    {
      if (y > 0)
	{
	  s->tab[y-1][x] = c;
	  x++;
	}
      if (c == '\n')
	{
	  y++;
	  x = 0;
	}
    }
}
