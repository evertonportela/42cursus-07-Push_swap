/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive_entries.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:44:55 by evportel          #+#    #+#             */
/*   Updated: 2023/10/05 22:30:12 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_receive_entries(int argc, char **argv)
{
	int	*entries;
	int	index;

	entries = (int *) malloc((argc - 1) * sizeof(int));
	if (entries == 0)
		return NULL;
	index = 0;
	while (index < argc -1)
	{
		entries[index] = ft_atoi(&argv[index + 1][0]);
		index++;
	}
	return (entries);
}