/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:50:10 by evportel          #+#    #+#             */
/*   Updated: 2023/10/18 21:06:00 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Verifica se a string de entrada representa um número inteiro válido.
 *
 * @param str_input A string de entrada a ser verificada.
 * @return	Um valor de saída que indica o sucesso (EXIT_SUCCESS) 
 * 			ou falha (EXIT_FAILURE) da verificação.
 */
static int ft_is_integer(char *str_input) 
{
    int index;
    int negative;

	index = 0;
    negative = 0;
    if (str_input[0] == '-') 
	{
        // Define 'negative' como 1 se o primeiro caractere for um sinal de menos ("-").
		negative = 1;
    }

    while (str_input[index] != '\0') 
	{
        if (!ft_isdigit(str_input[index])) 
		{
            // Se algum caractere não for um dígito, a string não representa um número inteiro válido.
            return EXIT_FAILURE;
        }
        index++;
    }

    if (negative == 1 && -ft_atoi(str_input) < INT_MIN) 
	{
        // Se a string for negativa e o valor absoluto for menor que o limite mínimo de um inteiro, é inválida.
        return EXIT_FAILURE;
    }
    if (negative == 0 && ft_atoi(str_input) > INT_MAX) 
	{
        // Se a string for positiva e o valor for maior que o limite máximo de um inteiro, é inválida.
        return EXIT_FAILURE;
    }
	// A string representa um número inteiro válido.
    return EXIT_SUCCESS;
}

/**
 * Valida os argumentos de entrada do programa.
 *
 * @param argc O número de argumentos de linha de comando.
 * @param argv Um array de strings contendo os argumentos de linha de comando.
 * @return Um valor de saída que indica o sucesso (EXIT_SUCCESS) 
 * ou falha (EXIT_FAILURE) da validação.
 */
int	ft_valid_args(int argc, char **argv)
{
	int	index;
	int	flag;

	index = 0;
	flag = 0;
	while (index < argc)
	{
		flag = ft_is_integer(argv[index]);
        // Se algum argumento não for um número inteiro válido, 
		// exibe uma mensagem de erro e sai com falha.
		if (flag == EXIT_FAILURE)
			ft_push_swap_error();
		index++;
	}
	// Todos os argumentos são válidos.
	return (EXIT_SUCCESS);
}
