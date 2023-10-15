/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:30:58 by evportel          #+#    #+#             */
/*   Updated: 2023/10/15 16:47:15 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483647
# define INT_MAX 2147483647

# include "./libft/libft.h"		/* libtf */
# include "stdlib.h"			/* EXIT_SUCCESS */
# include "unistd.h"			/* malloc, free */

typedef struct s_stack
{
	char			*content;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stack_pack
{
	int		limit;
	int		length;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_stack_pack;

void	ft_push_swap_error(void);
int		ft_valid_args(int length, char **argv);
void	ft_receive_inputs(int length, char **argv, int *array_numbers);
int		*ft_get_start_index(int length, int *array_number);
char	**ft_make_binaries(int length, int *numbers);
t_stack	*ft_push_swap_lst_new(char *content, int index);
t_stack	*ft_push_swap_lst_last(t_stack *list);
void	ft_push_swap_lst_add_back(t_stack **list, t_stack *next);
t_stack	*ft_push_swap_lst_prev_last(t_stack *list);
void	ft_push_swap_lst_add_front(t_stack **list, t_stack *new);

void	ft_print_stack(int *stack, int size);

#endif