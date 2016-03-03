##
## Makefile for  in /home/maison_f/Epitech/rendu/CPE_2015_BSQ
## 
## Made by Maisonnave Florian
## Login   <maison_f@epitech.net>
## 
## Started on  Tue Dec 15 23:41:03 2015 Maisonnave Florian
## Last update Thu Mar  3 15:43:13 2016 Maisonnave Florian
##

CC	= gcc -Iinclude

RM	= rm -f

NAME	= bsq

SRCS	= src/bsq.c \
	  src/fonctions.c \
	  src/my_getnbr.c \
	  src/create.c \
	  src/display.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
