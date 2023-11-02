/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_short.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:07:06 by evportel          #+#    #+#             */
/*   Updated: 2023/11/01 21:05:38 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_pos_0_largest_pos_1(int pos_0, int pos_1, int pos_2,
			t_stack_pack *pack)
{
	if (pos_1 > pos_2)
	{
		ft_swap_a(pack);
		ft_reverse_rotate_a(pack);
		return (EXIT_SUCCESS);
	}
	if (pos_0 > pos_2)
	{
		ft_rotate_a(pack);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_swap_a(pack);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

static int	ft_pos_0_smallest_pos_1(int pos_0, int pos_2, t_stack_pack *pack)
{
	if (pos_0 > pos_2)
	{
		ft_reverse_rotate_a(pack);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_swap_a(pack);
		ft_rotate_a(pack);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

static int	ft_rotate_three_numbers(t_stack_pack *pack)
{
	int	position_0;
	int	position_1;
	int	position_2;

	position_0 = pack->stack_a->index;
	position_1 = pack->stack_a->next->index;
	position_2 = pack->stack_a->next->next->index;
	if ((position_0 < position_1) && (position_1 < position_2))
		return (EXIT_SUCCESS);
	if (position_0 > position_1)
	{
		ft_pos_0_largest_pos_1(position_0, position_1, position_2, pack);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_pos_0_smallest_pos_1(position_0, position_2, pack);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

void	ft_push_swap_short(t_stack_pack *pack)
{
	if (pack->length == 2)
	{
		ft_swap_a(pack);
		return ;
	}
	if (pack->length > 3)
	{
		while (pack->stack_a->index != 0)
			ft_rotate_a(pack);
		ft_push_b(pack);
		if (pack->length == 5)
		{
			while (pack->stack_a->index != 1)
				ft_rotate_a(pack);
			ft_push_b(pack);
		}
	}
	ft_rotate_three_numbers(pack);
	if (pack->length == 4)
		ft_push_a(pack);
	if (pack->length == 5)
	{
		ft_push_a(pack);
		ft_push_a(pack);
	}
}
