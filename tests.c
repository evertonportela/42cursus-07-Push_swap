#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	index;
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
		stack_b = ft_receive_entries(argc, argv);
		stack_b = ft_swap_a(stack_b);
		index = 0;
		while (index < (argc - 1))
		{
			ft_printf("Pilha A: %d\tPilha B: %d\n", stack_a[index], stack_b[index]);
			index++;
		}

		free(stack_a);
		free(stack_b);
		
	}
	return (EXIT_SUCCESS);
}
