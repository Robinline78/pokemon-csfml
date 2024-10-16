##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME	=	open_window.c	\
#./src/map.c	\

BIN_NAME	=	Pokemon-csfml

DELETE	=	-rm

CC	=	gcc

FLAGS	=	-I./include

CSFML_FLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:
	$(CC) -o $(BIN_NAME) $(NAME) $(FLAGS) $(CSFML_FLAGS)

clean:
	$(DELETE) *.gcda *.gcno unit_tests

fclean:
	$(DELETE) $(BIN_NAME)

re:	fclean all
