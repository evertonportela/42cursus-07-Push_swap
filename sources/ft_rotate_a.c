/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:35:14 by evportel          #+#    #+#             */
/*   Updated: 2023/10/15 18:30:12 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_stack_pack *pack)
{
	t_stack	*first;
	t_stack	*last;

	if (pack->stack_a != NULL)
	{
		first = pack->stack_a;
		last = pack->stack_a;
		while (last->next != NULL)
		{
			last = last->next;
		}
		pack->stack_a = first->next;
		first->next = NULL;
		last->next = first;
		ft_putstr_fd("ra\n", 1);
	}
}
