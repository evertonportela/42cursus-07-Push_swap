/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:48:22 by evportel          #+#    #+#             */
/*   Updated: 2023/10/11 21:47:13 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_check_is_negative(char *argv)
{
	int	negative;

	if (argv[0] == '-')
		negative = 0;
	else
		negative = 1;
	return (negative);
}

static int ft_check_is_digit(char *argv)
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

static int	ft_is_integer(char *argv)
{
	if (ft_check_is_digit(argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	
}

static void	ft_push_swap_error(int cod_exit, char *str)
{
	ft_putstr_fd("Push_Swap_Error: ", 2);
	if (cod_exit == 127)
		ft_putstr_fd("Command not found", 2);
	else if (cod_exit == 22)
		ft_putstr_fd("Invalid arguments", 2);
	if (str[0] != 0)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n", 2);
	if (cod_exit == 0)
		exit(cod_exit);
	else
		exit(EXIT_FAILURE);
}

static int	ft_valid_args(int argc, char **argv)
{
	int	index;
	int	flag;

	index = 0;
	flag = 0;
	while (index < argc)
	{
		flag = ft_is_integer(argv[index]);
		if (flag == 0)
		{
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int	*array_numbers;

	if (argc == 1)
		exit(EXIT_FAILURE);
	argc--;
	argv++;
	array_numbers = malloc (argc * sizeof(int));

	if (array_numbers == NULL)
		exit(EXIT_FAILURE);

	ft_valid_args(argc, argv);

	return (EXIT_FAILURE);
}

// int	main(int argc, char **argv)
// {
// 	int *stack_a;
// 	int *stack_b;

// 	if (argc < 2)
// 	{
// 		ft_printf("Error: Invalid arguments\n");
// 		return (EXIT_FAILURE);
// 	}
// 	else
// 	{
// 		stack_a = ft_receive_entries(argc, argv);
// 		ft_print_stack(stack_a, (argc - 1));
// 		stack_b = ft_receive_entries(argc, argv);
		
// 		stack_a = ft_push_pa_pb("pa", stack_a, ( argc - 1));
// 		ft_print_stack(stack_a, (argc - 1));

// 		free(stack_a);
// 		free(stack_b);
// 	}
// 	return (EXIT_SUCCESS);
// }
