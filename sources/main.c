/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:48:22 by evportel          #+#    #+#             */
/*   Updated: 2023/10/18 20:47:12 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Inicializa a estrutura t_stack_pack com valores iniciais.
 *
 * @param pack A estrutura que será inicializada.
 * @param length O tamanho da estrutura (número de elementos).
 */
static void	ft_init_struct(t_stack_pack *pack, int length)
{
    pack->length = length;	// Define o tamanho da estrutura com o valor fornecido.
    pack->stack_a = NULL;	// Inicializa a pilha stack_a como vazia.
    pack->stack_b = NULL;	// Inicializa a pilha stack_b como vazia.
}

/**
 * Carrega os números e suas representações binárias nas pilhas.
 *
 * @param pack A estrutura que contém as pilhas e informações.
 * @param array_bin Um array de strings contendo as representações binárias dos números.
 * @param array_numbers Um array de números de entrada.
 */
static void	ft_stack_charging(t_stack_pack *pack,
								char **array_bin, int *array_numbers)
{
	int	index;

	if (pack->length != 0)
	{
		index = 0;
        // Inicializa a pilha 'stack_a' com o primeiro número e sua representação binária.
		pack->stack_a = ft_push_swap_lst_new(array_bin[index],
				array_numbers[index]);
		while (index < (pack->length - 1))
		{
			index++;
            // Adiciona os números restantes à pilha 'stack_a'.
			ft_push_swap_lst_add_back(&pack->stack_a,
				ft_push_swap_lst_new(array_bin[index], array_numbers[index]));
		}
	}
}

/**
 * Função principal do programa.
 *
 * @param argc O número de argumentos de linha de comando.
 * @param argv Um array de strings contendo os argumentos de linha de comando.
 * @return Um valor de saída que indica o sucesso ou falha do programa.
 */
int	main(int argc, char **argv)
{
	int *array_numbers;		// Array para armazenar os números de entrada.
	int *start_index;		// Array de índices de início.
	char **binaries;		// Array de representações binárias dos números.
	t_stack_pack pack;		// Estrutura principal que contém as pilhas e informações.

	if (argc == 1)
	{
		// Se não houver argumentos de linha de comando, sai com erro.
		exit(EXIT_FAILURE);
    }
	// Decrementa a contagem de argumentos e avança o ponteiro de argumentos.
	argc--;
	argv++;

	// Aloca memória para o array de números e valida os argumentos de entrada.
	array_numbers = malloc (argc * sizeof(int));
	if (array_numbers == NULL)
		exit(EXIT_FAILURE);
	
	// Função para validar os argumentos.
	ft_valid_args(argc, argv);
    
	// Recebe os números de entrada e preenche o array 'array_numbers'.
    ft_receive_inputs(argc, argv, array_numbers);

    // Calcula os índices de início dos números em relação à ordenação.
    start_index = ft_get_start_index(argc, array_numbers);

    // Gera representações binárias dos números e inicializa a estrutura principal.
    binaries = ft_make_binaries(argc, start_index);
    ft_init_struct(&pack, argc);

    // Carrega os números nas pilhas e inicia o algoritmo "push-swap".
    ft_stack_charging(&pack, binaries, start_index);
    ft_push_swap(&pack);

    // Limpa a memória alocada e encerra o programa.
    ft_clean_project(&pack, array_numbers, start_index, binaries);
    
	// Retorna um valor de saída indicando erro.
	return EXIT_FAILURE;
}
