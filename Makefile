##
## EPITECH PROJECT, 2021
## MyTeams
## File description:
## Makefile
##

NAME		 	=	myftp

INCLUDES		= 	-I includes/

SRC_PATH		=	src/
COMMANDS_PATH	=	$(SRC_PATH)commands/

SRC				=	$(SRC_PATH)main.c						\
					$(SRC_PATH)create_server.c				\
					$(SRC_PATH)check_error.c				\
					$(SRC_PATH)loop.c						\
					$(SRC_PATH)client_handler.c				\
					$(SRC_PATH)split.c						\

SRC				+=	$(COMMANDS_PATH)commands_handler.c		\
					$(COMMANDS_PATH)is_logged.c				\
					$(COMMANDS_PATH)user.c					\
					$(COMMANDS_PATH)pass.c					\
					$(COMMANDS_PATH)noop.c					\
					$(COMMANDS_PATH)help.c					\
					$(COMMANDS_PATH)pwd.c					\
					$(COMMANDS_PATH)cwd.c					\
					$(COMMANDS_PATH)cdup.c					\

OBJ 			= 	$(SRC:.c=.o)

CFLAGS			=	-W					\
					-Wall				\
					-Wextra				\
					-Werror				\
					$(INCLUDES)

MV				= 	mv

LDFLAGS  	+=

RESET		=	\033[0m
RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
MAGENTA		=	\033[0;35m
CYAN		=	\033[1;36m
BOLD		=	\033[1m
NORMAL		=	\033[0m
PRINT_NAME 	= 	$(BOLD)$(CYAN)$(NAME)$(YELLOW)-> $(RESET)$(NORMAL)

all:	start

debug: CFLAGS += -g
debug: re

start: build_msg $(OBJ)
	@echo "$(PRINT_NAME) $(MAGENTA)Compilation successful$(RESET)\n"
	@echo "$(PRINT_NAME) $(MAGENTA)Building project...$(RESET)"
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) &&		\
	(echo "$(PRINT_NAME) $(MAGENTA)Building successful$(RESET)") ||	\
	(echo "$(PRINT_NAME) $(RED)Building failed$(RESET)")

build_msg:
	@echo "$(PRINT_NAME) $(MAGENTA)Compiling files... $(RESET)"

fclean:
	@echo "$(PRINT_NAME) $(MAGENTA)Cleaning source file... $(RESET)"
	@$(RM) -f ../$(NAME)
	@echo "$(PRINT_NAME) $(MAGENTA)Cleaning successful$(RESET)\n"

clean:
	@echo "$(PRINT_NAME) $(MAGENTA)Cleaning objects file... $(RESET)"
	@$(RM) -f $(OBJ)
	@echo "$(PRINT_NAME) $(MAGENTA)Cleaning successful$(RESET)\n"

re:	clean fclean start

.c.o:
	@ $(CC) -c $< -o $@ $(CFLAGS) && \
	  (printf "$(PRINT_NAME) $(GREEN)[✔]$(RESET)  $(CYAN)%b$(RESET)\n" $<) || \
	  (printf " $(RED)[X]$(RESET)  $(CYAN)%b$(RESET)\n" $< ; exit 1)

.PHONY:	all debug start fclean clean re