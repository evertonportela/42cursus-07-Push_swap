/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive_inputs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:16:52 by evportel          #+#    #+#             */
/*   Updated: 2023/10/12 12:19:28 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_duplicates(int argc, int *array_numbers)
{
	int	index;
	int	suspect;

	index = 0;
	while (index < argc)
	{
		suspect = index + 1;
		while (suspect < argc)
		{
			if (array_numbers[index] == array_numbers[suspect])
				return (EXIT_FAILURE);
			suspect++;
		}
		index++;
	}
	return (EXIT_SUCCESS);
}

void	ft_receive_inputs(int argc, char **argv, int *array_numbers)
{
	int	index;

	index = 0;
	while (index < argc)
	{
		array_numbers[index] = ft_atoi(argv[index]);
		index++;
	}
	if (ft_check_duplicates(argc, array_numbers) == EXIT_FAILURE) 
		ft_push_swap_error();
}
