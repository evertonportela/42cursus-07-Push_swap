/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_binaries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:27:59 by evportel          #+#    #+#             */
/*   Updated: 2023/10/18 20:05:36 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Calcula o número de vezes que 'length' pode ser dividido por 2 antes de se tornar zero.
 *
 * @param length O número a ser dividido.
 * @return O número de vezes que 'length' pode ser dividido por 2.
 */
int	ft_find_limit(int length)
{
	int	limit;		// O número de vezes que 'length' pode ser dividido por 2.

	limit = 0;
	while ((length / 2) != 0)
	{
        // Enquanto o valor de 'length' dividido por 2 não for zero, continue o loop.
		limit++;
		length = length / 2;
	}
	// Retorna o número de vezes que 'length' pode ser dividido por 2.
	return (limit);
}

/**
 * Converte um número inteiro em sua representação binária e retorna como uma string.
 *
 * @param length O número de dígitos necessários para representar o número.
 * @param number O número inteiro a ser convertido.
 * @return Uma string contendo a representação binária do número.
 */
static char	*ft_itob(int length, int number)
{
	int		limit;				// O número de dígitos necessários.
	int		bit_value;			// O valor do dígito binário atual (0 ou 1).
	int		bit_position;		// A posição do dígito binário atual.
	int		string_index;		// O índice da string binária.
	char	*binary_string;		// A string binária resultante.

    // Calcula o número de dígitos necessários para representar o número em binário (encontrando o limite de armazenamento).
	limit = ft_find_limit(length);
	
    // Aloca memória para a string binária com base no número de dígitos calculados.
	binary_string = (char *)malloc(limit * sizeof(char *) + 1);

    // Em caso de falha na alocação, encerra o programa.
	if (binary_string == NULL)
		exit(EXIT_FAILURE);
	
	bit_position = limit;
	string_index = 0;
	while (bit_position >= 0)
	{
        // Desloca o número original para a direita (bit a bit) para extrair o dígito binário da posição atual.
		bit_value = number >> bit_position;
		
        // Verifica se o dígito extraído é 0 ou 1 e o converte em caractere correspondente ('0' ou '1').
		if (bit_value & 1)
			*(binary_string + string_index) = 1 + '0';
		else
			*(binary_string + string_index) = 0 + '0';
		
		string_index++;
		bit_position--;
	}
    // Adiciona o caractere nulo '\0' para indicar o fim da string.
	*(binary_string + string_index) = '\0';
	
	// Retorna a string binária como resultado.	
	return (binary_string);
}

/**
 * Cria um array de strings contendo a representação binária de números inteiros.
 *
 * @param length O tamanho do array de números inteiros.
 * @param numbers O array de números inteiros.
 * @return Um novo array de strings contendo as representações binárias dos números.
 */
char	**ft_make_binaries(int length, int *numbers)
{
	int		index;			// Índice usado para percorrer o array de números inteiros.
	char	**array_bin;	// Um novo array de strings para armazenar as representações binárias.

    // Aloca memória para o novo array de strings com base no tamanho do array de números inteiros.
	array_bin = (char **)malloc(length * (sizeof(char **)) + 1);

	// Em caso de falha na alocação, encerra o programa.
	if (array_bin == NULL)
		exit(EXIT_FAILURE);

	index = 0;
	while (index < length)
	{
        // Converte o número inteiro em sua representação binária e armazena no novo array.
		array_bin[index] = ft_itob(length, numbers[index]);
		index++;
	}
	// Retorna o novo array de strings como resultado.
	return (array_bin);
}
