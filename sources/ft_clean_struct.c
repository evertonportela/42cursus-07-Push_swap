/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:55:26 by evportel          #+#    #+#             */
/*   Updated: 2023/10/15 19:01:25 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Função auxiliar para limpar a lista encadeada
*/
static	void ft_clean_list(t_stack **list)
{
	t_stack	*aux;
	t_stack *temp;

	aux = *list;
	// Se a lista estiver vazia, não há nada a fazer
	if (aux == NULL)
		return ;
	while (aux != NULL)
	{
		temp = aux->next;
		// Libera a memória alocada para o nó atual
		free(aux);
		aux = temp;
	}
	// Define o ponteiro da lista como NULL para indicar que está vazia
	*list = NULL;
}

/**
 * Função para limpar a estrutura principal e arrays associados
*/
void	ft_clean_project(t_stack_pack *pack, int *array_num, int *start_index,
															char **array_bin)
{
	int	index;

	// Libera a memória alocada para o array 'start_index'
	free(start_index);
	// Libera a memória alocada para o array 'array_num'
	free(array_num);
	
	/* Chama a função para limpar a lista encadeada 'stack_a' 
	* dentro da estrutura 'pack' */
	ft_clean_list(&pack->stack_a);
	/* Chama a função para limpar a lista encadeada 'stack_b' 
	* dentro da estrutura 'pack' */
	ft_clean_list(&pack->stack_b);
	index = 0;
	while (index < pack->length)
	{
		// Libera a memória alocada para cada string no array 'array_bin'
		free(array_bin[index]);
		index++;
	}
	// Libera a memória alocada para o array 'array_bin'
	free(array_bin);
}
