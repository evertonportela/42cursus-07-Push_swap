/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:55:26 by evportel          #+#    #+#             */
/*   Updated: 2023/10/24 22:39:50 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_swap_long(t_stack_pack *pack)
{
	int	count;

	count = 0;
	pack->limit = ft_find_limit(pack->length);
	while (pack->limit >= 0)
	{
		while (count < pack->length)
		{
			if (pack->stack_a->content[pack->limit] == '0')
				ft_push_b(pack);
			else
				ft_rotate_a(pack);
			count++;
		}
		while (pack->stack_b)
			ft_push_a(pack);
		pack->limit--;
		count = 0;
	}
}

void	ft_push_swap(t_stack_pack *pack)
{
	if (pack->length <= 5)
		ft_push_swap_short(pack);
	else
		ft_push_swap_long(pack);
}
