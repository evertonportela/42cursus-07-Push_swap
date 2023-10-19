/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive_inputs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:16:52 by evportel          #+#    #+#             */
/*   Updated: 2023/10/18 21:36:25 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Verifica se os números contidos no array estão em ordem crescente.
 *
 * @param argc O número de elementos no array.
 * @param array_num O array de números a ser verificado.
 * @return Um valor de saída que indica o sucesso (EXIT_SUCCESS) ou falha (EXIT_FAILURE) da verificação de ordenação.
 */
static int	ft_check_sort(int argc, int *array_num)
{
	int	index;

	index = 0;
	argc--;
	// Entra em um loop para verificar a ordenação crescente.
	while (index < argc && array_num[index] < array_num[index + 1])
	{
        // Incrementa 'index' para verificar o próximo par de elementos.
		index++;
	}
    // Se 'index' for igual a 'argc', significa que todos os elementos estão em ordem crescente.
	if (index == argc)
	{
        // e então retorna EXIT_FAILURE
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * Verifica se há duplicatas nos números contidos no array.
 *
 * @param argc O número de elementos no array.
 * @param array_numbers O array de números a ser verificado.
 * @return Um valor de saída que indica o sucesso (EXIT_SUCCESS) ou falha (EXIT_FAILURE) da verificação de duplicatas.
 */
static int	ft_check_duplicates(int argc, int *array_numbers)
{
	int	index;
	int	suspect;

	index = 0;
	while (index < argc)
	{
		// Define um índice 'suspect' para comparar com o número atual.
		suspect = index + 1;
		while (suspect < argc)
		{
			if (array_numbers[index] == array_numbers[suspect])
			{
                // Se um número for igual a outro número posterior, há uma duplicata.
				return (EXIT_FAILURE);
			}
			suspect++;
		}
		index++;
	}
	// Não foram encontradas duplicatas nos números.
	return (EXIT_SUCCESS);
}

/**
 * Recebe os argumentos de linha de comando, converte e armazena os números em um array.
 * Realiza verificações de duplicatas e ordenação.
 *
 * @param argc O número de argumentos de linha de comando.
 * @param argv Um array de strings contendo os argumentos de linha de comando.
 * @param array_numbers Um array que armazenará os números de entrada.
 */
void	ft_receive_inputs(int argc, char **argv, int *array_numbers)
{
	int	index;

	index = 0;
	while (index < argc)
	{
		// Converte a string em um número inteiro.
		array_numbers[index] = ft_atoi(argv[index]);
		index++;
	}
    if (ft_check_duplicates(argc, array_numbers) == EXIT_FAILURE) {
        // Verifica se há duplicatas nos números. Se encontradas, exibe uma mensagem de erro.
        ft_push_swap_error();
    }

    if (ft_check_sort(argc, array_numbers) == EXIT_FAILURE) {
        // Verifica se os números não estão em ordem. Se não estiverem, exibe uma mensagem de erro.
        ft_push_swap_error();
    }
}
