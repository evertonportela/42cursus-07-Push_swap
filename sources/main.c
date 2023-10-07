/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:48:22 by evportel          #+#    #+#             */
/*   Updated: 2023/10/07 18:34:59 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int *stack_a;
	int *stack_b;

	if (argc < 2)
	{
		ft_printf("Error: Invalid arguments\n");
		return (EXIT_FAILURE);
	}
	else
	{
		stack_a = ft_receive_entries(argc, argv);
		ft_print_stack(stack_a, (argc - 1));
		stack_b = ft_receive_entries(argc, argv);
		
		stack_a = ft_push_pa_pb("pa", stack_a, ( argc - 1));
		ft_print_stack(stack_a, (argc - 1));

		free(stack_a);
		free(stack_b);
	}
	return (EXIT_SUCCESS);
}
