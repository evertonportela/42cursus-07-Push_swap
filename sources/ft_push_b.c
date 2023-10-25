/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:52:35 by evportel          #+#    #+#             */
/*   Updated: 2023/10/24 22:42:43 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b(t_stack_pack *pack)
{
	t_stack	*first;

	if (pack->stack_a != NULL)
	{
		first = pack->stack_a;
		pack->stack_a = first->next;
		first->next = pack->stack_b;
		pack->stack_b = first;
		ft_putstr_fd("pb\n", 1);
	}
}
