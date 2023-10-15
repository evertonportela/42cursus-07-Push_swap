/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:35:14 by evportel          #+#    #+#             */
/*   Updated: 2023/10/15 18:30:09 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_b(t_stack_pack *pack)
{
	t_stack	*first;
	t_stack	*last;

	if (pack->stack_b != NULL)
	{
		first = pack->stack_b;
		last = pack->stack_b;
		while (last->next != NULL)
		{
			last = last->next;
		}
		pack->stack_b = first->next;
		first->next = NULL;
		last->next = first;
		ft_putstr_fd("rb\n", 1);
	}
}
