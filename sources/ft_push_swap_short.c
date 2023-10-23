/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_short.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:07:06 by evportel          #+#    #+#             */
/*   Updated: 2023/10/15 19:00:22 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_pos_0_largest_pos_1(int pos_0, int pos_1, int pos_2,
			t_stack_pack *pack)
{
	if (pos_1 > pos_2)
	{
		ft_swap_a(pack);
		ft_reverse_rotate_a(pack);
		return (EXIT_SUCCESS);
	}
	if (pos_0 > pos_2)
	{
		ft_rotate_a(pack);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_swap_a(pack);
		return (EXIT_SUCCESS);
	}
		return (EXIT_FAILURE);
}

static int	ft_pos_0_smallest_pos_1(int pos_0, int pos_2, t_stack_pack *pack)
{
	if (pos_0 > pos_2)
	{
		ft_reverse_rotate_a(pack);
		return (EXIT_SUCCESS);
	}
	else 
	{
		ft_swap_a(pack);
		ft_rotate_a(pack);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

static int	ft_rotate_three_numbers(t_stack_pack *pack)
{
	int	position_0;
	int	position_1;
	int	position_2;

	position_0 = pack->stack_a->index;
	position_1 = pack->stack_a->next->index;
	position_2 = pack->stack_a->next->next->index;
	if ((position_0 < position_1) && (position_1 < position_2))
		return (EXIT_SUCCESS);
	if (position_0 > position_1)
	{
		ft_pos_0_largest_pos_1(position_0, position_1, position_2, pack);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_pos_0_smallest_pos_1(position_0, position_2, pack);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/**
 * Função para ordenar pilhas com 3 ou mais números.
 * Caso geral para tamanhos de pilha maiores que 3.
 *
 * @param pack - Estrutura que contém as pilhas e informações.
 */
void	ft_push_swap_short(t_stack_pack *pack)
{
	if (pack->length > 3)
	{
        // Enquanto o número mais baixo não estiver no topo da pilha A, gire.
		while (pack->stack_a->index != 0)
			ft_rotate_a(pack);

        // Mova o número mais baixo (índice 0) para a pilha B.
		ft_push_b(pack);

        // Se o tamanho da pilha for igual a 5, garanta que os dois números mais baixos estejam em B.
		if (pack->length == 5)
		{
            // Gire até que o número de índice 1 esteja no topo de A.
			while (pack->stack_a->index != 1)
				ft_rotate_a(pack);
            // Mova o número de índice 1 para B.
			ft_push_b(pack);
		}
	}
    // Ordene os três números restantes na pilha A.
	ft_rotate_three_numbers(pack);

    // Caso específico: se o tamanho da pilha for igual a 4, mova o número mais alto de B para A.
	if (pack->length == 4)
		ft_push_a(pack);

    // Caso específico: se o tamanho da pilha for igual a 5, mova os dois números mais baixos de B para A.
	if (pack->length == 5)
	{
		ft_push_a(pack);
		ft_push_a(pack);
	}
}
