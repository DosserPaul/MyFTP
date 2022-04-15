##
## EPITECH PROJECT, 2021
## Malloc
## File description:
## Makefile
##

NAME			=	myftp

INCLUDES		= 	./includes/

SRC_PATH		=	src/

SRC				=	$(SRC_PATH)main.c			\
					$(SRC_PATH)create_server.c	\
					$(SRC_PATH)check_error.c	\
					$(SRC_PATH)loop.c			\

OBJ 			= 	$(SRC:.c=.o)

CFLAGS			=	-I $(INCLUDES)		\
					-W					\
					-Wall				\
					-Wextra				\
#					-Werror				\


LDFLAGS  	+=

all:	start

debug: CFLAGS += -g
debug: re

start:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) -g

fclean:
	$(RM) -f $(NAME)

clean:
	$(RM) -f $(OBJ_NM)

re:	clean fclean all

.PHONY:	clean fclean re debug all