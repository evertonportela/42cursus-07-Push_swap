/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:30:58 by evportel          #+#    #+#             */
/*   Updated: 2023/10/14 18:40:03 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483647
# define INT_MAX 2147483647

# include "./libft/libft.h"		/* libtf */
# include "stdlib.h"			/* EXIT_SUCCESS */
# include "unistd.h"			/* malloc, free */

/**
 * Project functions prototypes
*/
void	ft_push_swap_error(void);
int		ft_valid_args(int length, char **argv);
void	ft_receive_inputs(int length, char **argv, int *array_numbers);
int		*ft_get_start_index(int length, int *array_number);
char	**ft_make_binaries(int length, int *numbers);


void	ft_print_stack(int *stack, int size);

#endif