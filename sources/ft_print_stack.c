/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:37:09 by evportel          #+#    #+#             */
/*   Updated: 2023/10/07 16:37:20 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(int *stack, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		ft_printf("%d\n", stack[index]);
		index++;
	}
}
