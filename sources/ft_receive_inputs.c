/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive_inputs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:16:52 by evportel          #+#    #+#             */
/*   Updated: 2023/10/28 16:17:36 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_sort(int argc, int *array_num)
{
	int	index;

	index = 0;
	argc--;
	while (index < argc && array_num[index] < array_num[index + 1])
		index++;
	if (index == argc)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

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
	{
		ft_putstr_fd("Error\n", 2);
		ft_push_swap_error_alloc(array_numbers);
	}
	if (ft_check_sort(argc, array_numbers) == EXIT_FAILURE)
		ft_push_swap_error_alloc(array_numbers);
}
