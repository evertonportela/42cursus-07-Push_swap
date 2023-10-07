/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:55:40 by evportel          #+#    #+#             */
/*   Updated: 2023/10/07 18:06:59 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_swap_first_second(int *stack)
{
	int index;
	int	aux;

	index = 0;
	aux = stack[index];
	stack[index] = stack[index + 1];
	stack[index + 1] = aux;	
	return (stack);
}

void	ft_swap_ss(int *stack_a, int *stack_b, int size)
{
	if (size > 1)
	{
		stack_a = ft_swap_first_second(stack_a);
		stack_b = ft_swap_first_second(stack_b);
		ft_printf("ss\n");
	}
}
