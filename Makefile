##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## ok
##

SRC	=	*.c

NAME	=	mysh

all:
	gcc	-o	$(NAME)	$(SRC)	-g3

clean:
	rm	-f	*#

fclean:	clean
	rm	-f	$(NAME)

re:	fclean all
