# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evportel <evportel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 22:04:00 by evportel          #+#    #+#              #
#    Updated: 2023/10/05 22:28:16 by evportel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOR ********************************************************************** #
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
MAGENTA	=	\033[35m
CYAN	=	\033[36m
RESET	=	\033[0m

# FLAGS MANDATORY ************************************************************ #
NAME	=	push_swap
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror
LIBFT	= -L ./libft -lft

SRC		=	main.c	ft_receive_entries.c

OBJ		=	${SRC:.c=.o}

HEADER	=	-I ./

# RULES MANDATORY ************************************************************ #
%.o: %.c
			@printf "${YELLOW}Compiling: ${CYAN}${notdir $<}${RESET}\n"
			@${CC} ${FLAGS} ${HEADER} -c $< -o $@

mylibft:
			@make -j8 -C ./libft/ --no-print-directory

${NAME}:	${OBJ} | mylibft
			@printf "${BLUE}All objects created!${RESET}\n"
			@${CC} ${FLAGS} -o ${NAME} ${HEADER} ${OBJ} ${LIBFT}
			@printf "${GREEN}${NAME} created!${RESET}\n"
			@exit 0

all:		${NAME}

# CLEANING RULES ************************************************************* #
clean:
			rm -fr ${OBJ}
			@make clean -C ./libft/ --no-print-directory
			@printf "${MAGENTA}All objects removed!${RESET}\n"

fclean:		clean
			rm -fr ${NAME}
			@make fclean -C ./libft/ --no-print-directory
			@printf "${RED}${NAME} removed!${RESET}\n"

re:			fclean all

.PHONY: all bonus clean fclean re