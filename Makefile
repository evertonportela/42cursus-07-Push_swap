# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evportel <evportel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 22:04:00 by evportel          #+#    #+#              #
#    Updated: 2023/10/06 21:33:39 by evportel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS ********************************************************************* #
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
MAGENTA	=	\033[35m
CYAN	=	\033[36m
RESET	=	\033[0m

# FLAGS MANDATORY ************************************************************ #
NAME		=	push_swap
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
LIBFT		=	-L ./libft -lft

SRC			=	main.c	ft_receive_entries.c

OBJ			=	${SRC:.c=.o}
HEADER		=	-I ./

# RULES MANDATORY ************************************************************ #
%.o: %.c
			@printf "${YELLOW}Compiling: ${CYAN}${notdir $<}${RESET}\n"
			${CC} ${FLAGS} ${HEADER} -c $< -o $@

all:		${NAME}

mylibft:
			@make -j21 -C ./libft/ --no-print-directory
#			@printf "${BLUE}All libft objects have been created!${RESET}\n"

${NAME}:	${OBJ} | mylibft
			@printf "${BLUE}All libft objects have been created!${RESET}\n"
			@printf "${BLUE}${NAME} objects have been created!${RESET}\n"
			${CC} ${FLAGS} -o ${NAME} ${OBJ} ${LIBFT} ${HEADER}
			@printf "${GREEN}${NAME} - Compilado com sucesso!${RESET}\n"



# CLEANING RULES ************************************************************* #
clean:
			rm -fr ${OBJ}
			@make clean -C ./libft/ --no-print-directory
			@printf "${MAGENTA}All objects removed!${RESET}\n"

fclean:		clean
			rm -fr ${NAME}
			@make fclean -C ./libft/ --no-print-directory
			@printf "${RED}${NAME} removed!${RESET}\n"

re:			fclean ${NAME}

# TEST RULES ***************************************************************** #
norm:
			norminette

valgrind:	
			valgrind -s --leak-check=yes ./push_swap 10 9 8 7 6 5 4 3 2 1 0

.PHONY: all bonus clean fclean re