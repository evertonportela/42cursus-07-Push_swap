/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:55:26 by evportel          #+#    #+#             */
/*   Updated: 2023/10/18 20:14:41 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Função responsável por classificar pilhas longas (mais de 5 elementos) usando o algoritmo Push Swap.
 *
 * @param pack Uma estrutura que contém as pilhas e outras informações necessárias.
 */
static void	ft_push_swap_long(t_stack_pack *pack)
{
	int	count;

	count = 0;

	// Calcula o limite com base no tamanho da pilha
	pack->limit = ft_find_limit(pack->length);
	while (pack->limit >= 0)
	{
		while(count < pack->length)
		// Verifica o bit no índice 'pack->limit' do elemento atual da pilha A
		{
			if (pack->stack_a->content[pack->limit] == '0')
			{
				// Empilha o elemento na pilha B
				ft_push_b(pack);
			}
			else
			{
				// Rotaciona a pilha A
				ft_rotate_a(pack);
			}
			count++;
		}
		while (pack->stack_b)
		{
			// Desempilha elementos da pilha B de volta para a pilha A
			ft_push_a(pack);
		}
		// Reduz o limite para processar o próximo bit significativo
		pack->limit--;
		// Reinicia o contador para processar o próximo bit
		count = 0;
	}
}

/**
 * Função principal que inicia o processo de classificação das pilhas.
 *
 * @param pack Uma estrutura que contém as pilhas e outras informações necessárias.
 */
void	ft_push_swap(t_stack_pack *pack)
{
	// Se o tamanho da pilha for menor ou igual a 5, use uma estratégia de classificação curta.
	if (pack->length <= 5 )
		ft_push_swap_short(pack);
	
	// Caso contrário, use uma estratégia de classificação longa.
	else
		ft_push_swap_long(pack);
}
