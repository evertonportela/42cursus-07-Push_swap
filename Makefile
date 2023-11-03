# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evportel <evportel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 22:04:00 by evportel          #+#    #+#              #
#    Updated: 2023/11/02 21:36:21 by evportel         ###   ########.fr        #
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
#FLAGS		=	-Wall -Wextra -Werror -O3
FLAGS		=	-Wall -Wextra -Werror -g3
LIBFT		=	-L ./libft -lft

SRC			=	${addprefix sources/, ft_atoi.c} \
				${addprefix sources/, ft_clean_struct.c} \
				${addprefix sources/, ft_get_start_index.c} \
				${addprefix sources/, ft_isdigit.c} \
				${addprefix sources/, ft_make_binaries.c} \
				${addprefix sources/, ft_push_a.c} \
				${addprefix sources/, ft_push_b.c} \
				${addprefix sources/, ft_push_swap_error.c} \
				${addprefix sources/, ft_push_swap_list_operations.c} \
				${addprefix sources/, ft_push_swap_short.c} \
				${addprefix sources/, ft_push_swap.c} \
				${addprefix sources/, ft_putstr_fd.c} \
				${addprefix sources/, ft_receive_inputs.c} \
				${addprefix sources/, ft_reverse_rotate_a.c} \
				${addprefix sources/, ft_reverse_rotate_b.c} \
				${addprefix sources/, ft_rotate_a.c} \
				${addprefix sources/, ft_rotate_b.c} \
				${addprefix sources/, ft_swap_a.c} \
				${addprefix sources/, ft_swap_b.c} \
				${addprefix sources/, ft_validate_arguments.c} \
				${addprefix sources/, main.c}

OBJ			=	${SRC:.c=.o}
HEADER		=	-I ./

# RULES MANDATORY ************************************************************ #
%.o: %.c
			@printf "${YELLOW}Compiling: ${CYAN}${notdir $<}${RESET}\n"
			${CC} ${FLAGS} ${HEADER} -c $< -o $@

all:		${NAME}

#mylibft:
#			@make -j21 -C ./libft/ --no-print-directory
#			@printf "${BLUE}All libft objects have been created!${RESET}\n"

#${NAME}:	${OBJ} | mylibft
#			@printf "${BLUE}All libft objects have been created!${RESET}\n"
#			@printf "${BLUE}${NAME} objects have been created!${RESET}\n"
#			${CC} ${FLAGS} -o ${NAME} ${OBJ} ${LIBFT} ${HEADER}
#			@printf "${GREEN}${NAME} - Compiled successfully!${RESET}\n"

${NAME}:	${OBJ}
			@printf "${BLUE}${NAME} objects have been created!${RESET}\n"
			${CC} ${FLAGS} -o ${NAME} ${OBJ} ${HEADER}
			@printf "${GREEN}${NAME} - Compiled successfully!${RESET}\n"


# CLEANING RULES ************************************************************* #
#clean:
#			rm -fr ${OBJ}
#			@printf "${MAGENTA}${NAME} project objects removed!${RESET}\n"
#			@make clean -C ./libft/ --no-print-directory
#			@printf "${MAGENTA}Libft objects removed!${RESET}\n"
clean:
			rm -fr ${OBJ}
			@printf "${MAGENTA}${NAME} project objects removed!${RESET}\n"

#fclean:		clean
#			rm -fr ${NAME}
#			@make fclean -C ./libft/ --no-print-directory
#			@printf "${RED}Executable ${NAME} removed!${RESET}\n"

fclean:		clean
			rm -fr ${NAME}
			@printf "${RED}Executable ${NAME} removed!${RESET}\n"

re:			fclean ${NAME}

# TEST RULES ***************************************************************** #
norm:
			norminette

valgrind:	
			valgrind -s --leak-check=yes --track-origins=yes ./push_swap 2 1 3 --A 9
#			valgrind -s --leak-check=yes --track-origins=yes ./push_swap 2 1 3 6 5 8 9

visu:
			./visualizer/build/bin/visualizer
			

.PHONY: all bonus clean fclean re