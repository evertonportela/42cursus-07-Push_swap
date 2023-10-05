# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evportel <evportel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 22:04:00 by evportel          #+#    #+#              #
#    Updated: 2023/10/04 22:08:46 by evportel         ###   ########.fr        #
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

SRC		=	main.c

OBJ		=	${SRC:.c=.o}

HEADER	=	push_swap.h

# RULES MANDATORY ************************************************************ #
all:		${NAME}

${NAME}:	${OBJ}
	@printf "${BLUE}All objects created!${RESET}\n"
	@cc ${FLAGS} -Iinclude ${OBJ} -o $@
	@printf "${GREEN}${NAME} created!${RESET}\n"
	@exit 0

%.o: %.c
	@printf "${YELLOW}Compiling: ${CYAN}${notdir $<}${RESET}\n"
	@cc ${FLAGS} -Iinclude -c $< -o $@

# CLEANING RULES ************************************************************* #
clean:
	@rm -fr ${OBJ}
#	@rm -fr ${OBJ_BONUS}
	@printf "${MAGENTA}All objects removed!${RESET}\n"

fclean:		clean
	@rm -fr ${NAME}
#	@rm -fr ${NAME_BONUS}
	@printf "${RED}${NAME} removed!${RESET}\n"

re:			fclean ${NAME}

.PHONY: all bonus clean fclean re