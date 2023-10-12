/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_first_second.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:55:40 by evportel          #+#    #+#             */
/*   Updated: 2023/10/07 17:48:17 by evportel         ###   ########.fr       */
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

int	*ft_swap_sa_sb(char *operation, int *stack, int size)
{
	if (size < 2)
		return (stack);
	if (ft_strncmp(operation, "sa", 2) == 0)
	{
		stack = ft_swap_first_second(stack);
		ft_printf("sa\n");
	}
	else if (ft_strncmp(operation, "sb", 2) == 0)
	{
		stack = ft_swap_first_second(stack);
		ft_printf("sb\n");
	}
	return (stack);
}
