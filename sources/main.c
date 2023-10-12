/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:48:22 by evportel          #+#    #+#             */
/*   Updated: 2023/10/12 11:37:53 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*array_numbers;

	if (argc == 1)
		ft_push_swap_error(1, "Invalid arguments\nUse ./push_swap Num Num ...");
	argc--;
	argv++;
	array_numbers = malloc (argc * sizeof(int));
	if (array_numbers == NULL)
		exit(EXIT_FAILURE);
	ft_valid_args(argc, argv);
	ft_receive_inputs(argc, argv, array_numbers);
	ft_printf("%d ", array_numbers[0]);
	ft_printf("%d ", array_numbers[1]);
	return (EXIT_FAILURE);
}
