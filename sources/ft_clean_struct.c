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

static void	ft_clean_list(t_stack **list)
{
	t_stack	*aux;
	t_stack	*temp;

	aux = *list;
	if (aux == NULL)
		return ;
	while (aux != NULL)
	{
		temp = aux->next;
		free(aux);
		aux = temp;
	}
	*list = NULL;
}

void	ft_clean_project(t_stack_pack *pack, int *array_num, int *start_index,
	char **array_bin)
{
	int	index;

	free(start_index);
	free(array_num);
	ft_clean_list(&pack->stack_a);
	ft_clean_list(&pack->stack_b);
	index = 0;
	while (index < pack->length)
	{
		free(array_bin[index]);
		index++;
	}
	free(array_bin);
}
