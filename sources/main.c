/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:48:22 by evportel          #+#    #+#             */
/*   Updated: 2023/11/01 21:23:15 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_struct(t_stack_pack *pack, int length)
{
	pack->length = length;
	pack->stack_a = NULL;
	pack->stack_b = NULL;
}

static void	ft_stack_charging(t_stack_pack *pack,
	char **array_bin, int *array_numbers)
{
	int	index;

	if (pack->length != 0)
	{
		index = 0;
		pack->stack_a = ft_push_swap_lst_new(array_bin[index],
				array_numbers[index]);
		while (index < (pack->length - 1))
		{
			index++;
			ft_push_swap_lst_add_back(&pack->stack_a,
				ft_push_swap_lst_new(array_bin[index], array_numbers[index]));
		}
	}
}

int	main(int argc, char **argv)
{
	int				*array_numbers;
	int				*start_index;
	char			**binaries;
	t_stack_pack	pack;

	if (argc == 1)
		exit(EXIT_FAILURE);
	if (argc == 2)
		ft_push_swap_error();
	argc--;
	argv++;
	ft_valid_args(argc, argv);
	array_numbers = malloc (argc * sizeof(int));
	if (array_numbers == NULL)
		exit(EXIT_FAILURE);
	ft_receive_inputs(argc, argv, array_numbers);
	start_index = ft_get_start_index(argc, array_numbers);
	binaries = ft_make_binaries(argc, start_index);
	ft_init_struct(&pack, argc);
	ft_stack_charging(&pack, binaries, start_index);
	ft_push_swap(&pack);
	ft_clean_project(&pack, array_numbers, start_index, binaries);
	return (EXIT_FAILURE);
}
