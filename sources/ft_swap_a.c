/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:55:40 by evportel          #+#    #+#             */
/*   Updated: 2023/10/06 22:11:26 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_swap_a(int *stack, int size)
{
	int index;
	int	aux;

	if (size < 2)
		return (stack);
	index = 0;
	aux = stack[index];
	stack[index] = stack[index + 1];
	stack[index + 1] = aux;
	
	return (stack);
}
