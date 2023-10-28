/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:11:57 by evportel          #+#    #+#             */
/*   Updated: 2023/10/28 17:11:58 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int			index;
	int			mult;
	long int	number;

	index = 0;
	mult = 1;
	number = 0;
	while ((nptr[index] >= '\t' && nptr[index] <= '\r') || nptr[index] == ' ')
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index++] == '-')
			mult = mult * -1;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		number = (number * 10) + (nptr[index] - '0');
		index++;
	}
	number = number * mult;
	if (number > INT_MAX || number < INT_MIN)
		ft_push_swap_error();
	return (number);
}
