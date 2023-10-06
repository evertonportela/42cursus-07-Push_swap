/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:53:23 by evportel          #+#    #+#             */
/*   Updated: 2023/05/15 11:11:29 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	index;
	int	mult;
	int	number;

	index = 0;
	mult = 1;
	number = 0;
	while ((nptr[index] >= '\t' && nptr[index] <= '\r') || nptr[index] == ' ')
	{
		index++;
	}
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index++] == '-')
		{
			mult = mult * -1;
		}
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		number = (number * 10) + (nptr[index] - '0');
		index++;
	}
	number = number * mult;
	return (number);
}
