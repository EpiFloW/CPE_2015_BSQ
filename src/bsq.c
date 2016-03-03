/*
** bsq.c for  in /home/maison_f/Epitech/rendu/CPE_2015_BSQ
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Sun Dec 20 22:12:50 2015 Maisonnave Florian
** Last update Mon Dec 21 18:43:29 2015 Maisonnave Florian
*/

#include "struct.h"

void	free_tab(t_list *s)
{
  int	i;

  i = 0;
  while (i < s->nb_lines)
    {
      free(s->tab[i]);
      i++;
    }
  free(s->tab);
  free(s);
}

void	malloc_tab(t_list *s)
{
  int	i;

  s->tab = malloc(sizeof(char*) * (s->nb_lines + 1));
  i = 0;
  while (i < s->nb_lines)
    {
      s->tab[i] = malloc(sizeof(char) * (s->nb_colons + 1));
      i++;
    }
}

int	compt_lines(char *av1)
{
  char	*str;
  char	c;
  int	fd;
  int	i;
  int	result;

  i = 0;
  c = 0;
  str = malloc(sizeof(char*));
  fd = open(av1, O_RDONLY);
  while (c != '\n')
    {
      read(fd, &c, 1);
      str[i] = c;
      i++;
    }
  str[i] = '\0';
  result = my_getnbr(str);
  free(str);
  return (result);
}
int	compt_colons(char *av1)
{
  char	c;
  int	fd;
  int	x;
  int	y;

  y = 0;
  x = 0;
  fd = open(av1, O_RDONLY);
  while (y < 2)
    {
      read(fd, &c, 1);
      if (c == '\n')
	y++;
      if (y > 0)
	x++;
    }
  close(fd);
  x = x - 1;
  return (x);
}

int	main(int ac, char **av)
{
  t_list	*s;
  int		test;

  if (error(ac, av, test) == 1)
    return (0);
  s = malloc(sizeof(t_list));
  s->nb_colons = compt_colons(av[1]);
  s->nb_lines = compt_lines(av[1]);
  malloc_tab(s);
  create_tab(s, av[1]);
  test = test_o(s);
  if (test == 1)
    {
      algorithm(s);
      display(s);
    }
  if (test == 0)
    display_id(s);
  free_tab(s);
  return (0);
}
