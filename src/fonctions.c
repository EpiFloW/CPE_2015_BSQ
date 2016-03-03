/*
** fonctions.c for  in /home/maison_f/Epitech/rendu/CPE_2015_BSQ
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Tue Dec 15 22:51:51 2015 Maisonnave Florian
** Last update Sun Dec 20 22:43:24 2015 Maisonnave Florian
*/

#include "struct.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	my_putnbr(int nb)
{
  int	i;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  i = nb % 10;
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar(i + 48);
}
