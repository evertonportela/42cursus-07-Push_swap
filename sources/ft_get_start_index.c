/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_start_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:42:05 by evportel          #+#    #+#             */
/*   Updated: 2023/10/20 22:16:38 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Obtém o índice de cada número no array original após a ordenação.
 *
 * @param length O tamanho do array.
 * @param array_numbers O array de números original.
 * @param array_copy_sort O array de números ordenado.
 * @return Um novo array contendo os índices dos números no array ordenado.
 */
static int *ft_copy_array(int length, int *array_numbers)
{
	int	*copy;		// Um novo array para armazenar a cópia dos números.
	int	index;		// Índice usado para percorrer o array original.

    // Aloca memória para o novo array com base no tamanho do array original.
	copy = malloc(length * sizeof(int));
	if (copy == NULL)
	{
        // Em caso de falha na alocação, encerra o programa.
		exit(EXIT_FAILURE);
	}
    // Copia cada elemento do array original para o novo array.
	index = 0;
	while (index < length)
	{
		copy[index] = array_numbers[index];
		index++;
	}
	// Retorna o novo array como resultado.
	return (copy);
}

/**
 * Obtém o índice de cada número no array original após a ordenação.
 *
 * @param length O tamanho do array.
 * @param array_numbers O array de números original.
 * @param array_copy_sort O array de números ordenado.
 * @return Um novo array contendo os índices dos números no array ordenado.
 */
static int	*ft_get_index(int length, int *array_numbers, int *array_copy_sort)
{
	int	*array_index;	// Um array para armazenar os índices dos números.
	int	index;			// Índice atual no array.
	int	position;		// Posição do número no array ordenado.

    // Cria um novo array para armazenar os índices dos números no array ordenado.
	array_index = ft_copy_array(length, array_numbers);
	index = 0;
	while (index < length)
	{
		position = 0;
        // Encontra a posição do número no array ordenado.
		while (array_index[index] != array_copy_sort[position])
			position++;

        // Atualiza o índice no novo array com a posição do número no array ordenado.
		array_index[index] = position;
		index++;
	}
	// Retorna o novo array com os índices.
	return (array_index);
}

/**
 * Ordena o array de números e retorna o array ordenado.
 *
 * @param length O tamanho do array.
 * @param array_numbers O array de números a ser ordenado.
 * @return Um novo array contendo os números ordenados.
 */
static int	*ft_quick_sort(int length, int *array_numbers)
{
	int	*array_sort;	// Um array para armazenar os números ordenados.
	int	index;			// Índice atual.
	int	temp;			// Variável temporária para troca de elementos.

    // Cria uma cópia do array original para evitar a modificação do array original.
	array_sort = ft_copy_array(length, array_numbers);
	index = 0;
	
	// Ajusta o índice do último elemento do array.
	length = length - 1;

    // Implementação do algoritmo Quick Sort.
	while (index < length)
	{
		if (array_sort[index] > array_sort[index + 1])
		{
            // Se o elemento atual for maior que o próximo, troca os elementos.
			temp = array_sort[index];
			array_sort[index] = array_sort[index + 1];
			array_sort[index + 1] = temp;
            // Reinicia o loop para garantir a ordenação completa.
			index = -1;
		}
		index++;
	}
	// Retorna o array ordenado.
	return (array_sort);
}

/**
 * Obtém os índices dos números no array ordenado a partir do array original.
 *
 * @param length O tamanho do array.
 * @param array_numbers O array de números original.
 * @return Um novo array contendo os índices dos números no array ordenado.
 */
int		*ft_get_start_index(int length, int *array_numbers)
{
	// Um array para armazenar os índices dos números.
	int	*array_index;
	// Um array para armazenar uma cópia ordenada do array original.
	int	*array_copy_sort;

    // Chama a função auxiliar 'ft_quick_sort' para ordenar o array original.
	array_copy_sort = ft_quick_sort(length, array_numbers);
	
	// Chama a função auxiliar 'ft_get_index' para calcular os índices com base na ordenação.
	array_index = ft_get_index(length, array_numbers, array_copy_sort);

	// Libera a memória alocada para o array ordenado, pois não é mais necessário.
	free(array_copy_sort);

	// Retorna o array de índices.
	return (array_index);
}
