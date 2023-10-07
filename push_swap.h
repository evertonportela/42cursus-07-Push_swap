/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:30:58 by evportel          #+#    #+#             */
/*   Updated: 2023/10/06 22:11:37 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"		/* libtf */
# include "stdlib.h"			/* EXIT_SUCCESS */
# include "unistd.h"			/* malloc, free */

int	ft_atoi(const char *nptr);
int	*ft_receive_entries(int argc, char **argv);
int	*ft_swap_a(int *stack, int size);

#endif