##
## EPITECH PROJECT, 2026
## My Hunter
## File description:
## Makefile
##

NAME	=	my_hunter

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Iinclude

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
