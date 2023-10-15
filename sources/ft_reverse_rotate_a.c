/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:37:06 by evportel          #+#    #+#             */
/*   Updated: 2023/10/15 18:43:17 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a(t_stack_pack *pack)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (pack->stack_a != NULL)
	{
		last = pack->stack_a;
		prev_last = NULL;
		while(last->next != NULL)
		{
			prev_last = last;
			last = last->next;
		}
		prev_last->next = NULL;
		last->next = pack->stack_a;
		pack->stack_a = last;
		ft_putstr_fd("rra\n", 1);
	}
}
