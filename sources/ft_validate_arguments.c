/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:50:10 by evportel          #+#    #+#             */
/*   Updated: 2023/10/24 22:29:42 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_integer(char *str_input)
{
	int	index;
	int	negative;

	index = 0;
	negative = 0;
	if (str_input[0] == '-')
		negative = 1;
	while (str_input[index] != '\0')
	{
		if (!ft_isdigit(str_input[index]))
			return (EXIT_FAILURE);
		index++;
	}
	if (negative == 1 && - ft_atoi(str_input) < INT_MIN)
		return (EXIT_FAILURE);
	if (negative == 0 && ft_atoi(str_input) > INT_MAX)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_valid_args(int argc, char **argv)
{
	int	index;
	int	flag;

	index = 0;
	flag = 0;
	while (index < argc)
	{
		flag = ft_is_integer(argv[index]);
		if (flag == EXIT_FAILURE)
			ft_push_swap_error();
		index++;
	}
	return (EXIT_SUCCESS);
}
