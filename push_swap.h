/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:30:58 by evportel          #+#    #+#             */
/*   Updated: 2023/10/12 12:02:35 by evportel         ###   ########.fr       */
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
int		ft_valid_args(int argc, char **argv);
void	ft_receive_inputs(int argc, char **argv, int *array_numbers);

#endif