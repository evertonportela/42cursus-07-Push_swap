/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:50:10 by evportel          #+#    #+#             */
/*   Updated: 2023/10/12 10:51:03 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_is_negative(char *argv)
{
	int	negative;

	if (argv[0] == '-')
		negative = 1;
	else
		negative = 0;
	return (negative);
}

static int	ft_check_is_digit(char *argv)
{
	if (argv[0] == '-' && !ft_isdigit(argv[1]))
		return (EXIT_FAILURE);
	if (argv[0] == '-' && argv[1] == '\0')
		return (EXIT_FAILURE);
	if (argv[0] != '-' && !ft_isdigit(argv[0]))
		return (EXIT_FAILURE);
	if (argv[0] == '\0')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_is_integer(char *str_input)
{
	int	index;
	int	negative;
	int	number;

	if (ft_check_is_digit(str_input) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	negative = ft_check_is_negative(str_input);			//	1 is negative, 0 is positive
	index = negative;
	number = 0;
	while (str_input[index] != '\0')
	{
		if (!ft_isdigit(str_input[index]))
			return (EXIT_FAILURE);
		number = (number * 10) + (str_input[index] - '0');
		if (negative == 1 && - number < INT_MIN)
			return (EXIT_FAILURE);
		if (negative == 0 && number > INT_MAX)
			return (EXIT_FAILURE);
		index++;
	}
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
		{
			ft_push_swap_error(1, "Invalid arguments");
			return (EXIT_FAILURE);
		}
		index++;
	}
	return (EXIT_SUCCESS);
}
