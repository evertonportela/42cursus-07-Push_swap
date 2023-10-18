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
 * Recebe um valor 'length' e calcula o número de vezes que 'length' 
 * pode ser dividido por '2', antes de se tornar zero.
 * Será usado para determinar o tamanho da alocação de memória necessária.
*/
int	ft_find_limit(int length)
{
	int	limit;

	limit = 0;
	while ((length / 2) != 0)
	{
		limit++;
		length = length / 2;
	}
	return (limit);
}

/**
 * Converte o 'number' recebido para a representação em binário 
 * e armazena numa string.
 * Calcula o limite de armzenamento e +1 para o '\0'
 * Faz uma operação de deslocamento à direita e extrai o bit mais significativo
 * Observe que esse mais significativo faz muita diferenca aqui.
 * Converte o valor usando referencial da tabela ASCII
 * e retonar a representação binária.
*/
static char	*ft_itob(int length, int number)
{
	int		limit;
	int		bit_value;
	int		bit_position;
	int		string_index;
	char	*binary_string;

	limit = ft_find_limit(length);
	
	binary_string = (char *)malloc(limit * sizeof(char *) + 1);
	if (binary_string == NULL)
		exit(EXIT_FAILURE);
	
	bit_position = limit;
	string_index = 0;
	while (bit_position >= 0)
	{
		bit_value = number >> bit_position;
		
		if (bit_value & 1)
			*(binary_string + string_index) = 1 + '0';
		else
			*(binary_string + string_index) = 0 + '0';
		
		string_index++;
		bit_position--;
	}

	*(binary_string + string_index) = '\0';
	
	return (binary_string);
}

char	**ft_make_binaries(int length, int *numbers)
{
	int		index;
	char	**array_bin;

	array_bin = (char **)malloc(length * (sizeof(char **)) + 1);
	// array_bin = (char **)malloc(length * (sizeof(char **)));
	if (array_bin == NULL)
		exit(EXIT_FAILURE);

	index = 0;
	while (index < length)
	{
		array_bin[index] = ft_itob(length, numbers[index]);
		ft_printf("%s\n", array_bin[index]);
		index++;
	}
	return (array_bin);
}
