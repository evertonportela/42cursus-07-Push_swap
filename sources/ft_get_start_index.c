/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_start_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:42:05 by evportel          #+#    #+#             */
/*   Updated: 2023/10/12 17:56:18 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int *ft_copy_array(int length, int *array_numbers)
{
	int	*copy;
	int	index;

	copy = malloc(length * sizeof(int));
	if (copy == NULL)
		exit(EXIT_FAILURE);
	index = 0;
	while (index < length)
	{
		copy[index] = array_numbers[index];
		index++;
	}
	return (copy);
}

static int	*ft_get_index(int length, int *array_numbers, int *array_copy_sort)
{
	int	*array_index;
	int	index;
	int	position;

	array_index = ft_copy_array(length, array_numbers);
	index = 0;
	while (index < length)
	{
		position = 0;
		while (array_index[index] != array_copy_sort[position])
			position++;
		array_index[index] = position;
		index++;
	}
	return (array_index);
}

static int	*ft_quick_sort(int length, int *array_numbers)
{
	int	*array_sort;
	int	index;
	int	temp;

	array_sort = ft_copy_array(length, array_numbers);
	index = 0;
	length = length - 1;
	while (index < length)
	{
		if (array_sort[index] > array_sort[index + 1])
		{
			temp = array_sort[index];
			array_sort[index] = array_sort[index + 1];
			array_sort[index + 1] = temp;
			index = -1;
		}
		index++;
	}
	return (array_sort);
}

int		*ft_get_start_index(int length, int *array_numbers)
{
	int	*array_index;
	int	*array_copy_sort;

	array_copy_sort = ft_quick_sort(length, array_numbers);
	array_index = ft_get_index(length, array_numbers, array_copy_sort);
	free(array_copy_sort);
	return (array_index);
}
