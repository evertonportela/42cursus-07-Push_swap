/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:24:37 by evportel          #+#    #+#             */
/*   Updated: 2023/10/15 18:29:57 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_b(t_stack_pack *pack)
{
	char	*first;
	char	*second;

	if (pack->stack_b != NULL)
	{
		first = pack->stack_b->content;
		second = pack->stack_b->next->content;
		pack->stack_b->content = second;
		pack->stack_b->next->content = first;
		ft_putstr_fd("sb\n", 1);
	}
}
