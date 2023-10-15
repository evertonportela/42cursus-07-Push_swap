/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_list_operations.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:22:38 by evportel          #+#    #+#             */
/*   Updated: 2023/10/15 16:46:52 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_push_swap_lst_new(char *content, int index)
{
	t_stack	*new_element;

	new_element = (t_stack *)malloc(sizeof(t_stack));
	if (new_element == NULL)
		exit(EXIT_FAILURE);
	new_element->content = content;
	new_element->index = index;
	new_element->next = NULL;
	return (new_element);
}

t_stack	*ft_push_swap_lst_last(t_stack *list)
{
	if (list == 0)
		return (0);
	while (list->next != 0)
		list = list->next;
	return (list);
}

void	ft_push_swap_lst_add_back(t_stack **list, t_stack *next)
{
	t_stack	*end;

	end = ft_push_swap_lst_last(*list);
	if (end != 0)
		end->next = next;
	else
		*list = next;
}

t_stack	*ft_push_swap_lst_prev_last(t_stack *list)
{
	if (list == 0)
		return (0);
	while (list->next->next != 0)
		list = list->next;
	return (list);
}

void	ft_push_swap_lst_add_front(t_stack **list, t_stack *new)
{
	new->next = *list;
	*list = new;
}
