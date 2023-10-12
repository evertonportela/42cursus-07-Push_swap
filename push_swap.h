/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:30:58 by evportel          #+#    #+#             */
/*   Updated: 2023/10/12 10:15:03 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483647
# define INT_MAX 2147483647

# include "./libft/libft.h"		/* libtf */
# include "stdlib.h"			/* EXIT_SUCCESS */
# include "unistd.h"			/* malloc, free */

int		ft_atoi(const char *nptr);
int		*ft_receive_entries(int argc, char **argv);
int		*ft_swap_sa_sb(char *operation, int *stack, int size);
void	ft_swap_ss(int *stack_a, int *stack_b, int size);
void	ft_print_stack(int *stack, int size);

#endif