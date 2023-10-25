/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:37:06 by evportel          #+#    #+#             */
/*   Updated: 2023/10/24 22:36:22 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_b(t_stack_pack *pack)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (pack->stack_b != NULL)
	{
		last = pack->stack_b;
		prev_last = NULL;
		while (last->next != NULL)
		{
			prev_last = last;
			last = last->next;
		}
		prev_last->next = NULL;
		last->next = pack->stack_b;
		pack->stack_b = last;
		ft_putstr_fd("rrb\n", 1);
	}
}
