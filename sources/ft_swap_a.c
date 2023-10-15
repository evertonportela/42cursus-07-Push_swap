/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:24:37 by evportel          #+#    #+#             */
/*   Updated: 2023/10/15 18:29:59 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack_pack *pack)
{
	char	*first;
	char	*second;

	if (pack->stack_a != NULL)
	{
		first = pack->stack_a->content;
		second = pack->stack_a->next->content;
		pack->stack_a->content = second;
		pack->stack_a->next->content = first;
		ft_putstr_fd("sa\n", 1);
	}
}
