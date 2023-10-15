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

 

void	ft_push_swap(t_stack_pack *pack, int *index)
{
	int i = index[0];   //remover
	i = 0;				//remover
	if (pack->length <= 5 )
		ft_push_swap_short(pack);
	// else
	// 	ft_push_swap_long();
}
