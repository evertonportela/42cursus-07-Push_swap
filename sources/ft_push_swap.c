/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:55:26 by evportel          #+#    #+#             */
/*   Updated: 2023/10/15 19:01:25 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sort a stack with more than 5 numbers
*/
// void	long_push_swap(t_all *all)
// {
// 	int	i;

// 	all->limit = find_limit(all->len);
// 	i = 0;
// 	while (all->limit >= 0)
// 	{
// 		while (i < all->len)
// 		{
// 			if (all->a->content[all->limit] == '0')
// 				pb(all);
// 			else
// 				ra(all);
// 			i++;
// 		}
// 		while (all->b)
// 			pa(all);
// 		all->limit--;
// 		i = 0;
// 	}
// }

static void	ft_push_swap_long(t_stack_pack *pack)
{
	int	count;

	count = 0;
	while (pack->limit >= 0)
	{
		while(count < pack->length)
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
	}
}

void	ft_push_swap(t_stack_pack *pack, int *index)
{
	int i = index[0];   //remover
	i = 0;				//remover
	if (pack->length <= 5 )
		ft_push_swap_short(pack);
	else
		ft_push_swap_long(pack);
}
