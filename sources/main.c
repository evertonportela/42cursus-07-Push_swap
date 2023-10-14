/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:48:22 by evportel          #+#    #+#             */
/*   Updated: 2023/10/14 18:38:45 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*array_numbers;
	int		*start_index;
	char	**binaries;

	if (argc == 1)
		exit(EXIT_FAILURE);
	argc--;
	argv++;
	array_numbers = malloc (argc * sizeof(int));
	if (array_numbers == NULL)
		exit(EXIT_FAILURE);
	ft_valid_args(argc, argv);
	ft_receive_inputs(argc, argv, array_numbers);

	start_index = ft_get_start_index(argc, array_numbers);
	binaries = ft_make_binaries(argc, start_index);
	
	free(array_numbers);
	free(start_index);
	return (EXIT_FAILURE);
}
