/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive_inputs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:16:52 by evportel          #+#    #+#             */
/*   Updated: 2023/10/12 11:26:00 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_receive_inputs(int argc, char **argv, int *array_numbers)
{
	int	index;

	index = 0;
	while (index < argc)
	{
		array_numbers[index] = ft_atoi(argv[index]);
		index++;
	}
}
