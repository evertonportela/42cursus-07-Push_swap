/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:45:00 by evportel          #+#    #+#             */
/*   Updated: 2023/10/12 10:46:10 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_error(int cod_exit, char *str)
{
	ft_putstr_fd("Push_Swap_Error", 2);
	if (cod_exit == 127)
		ft_putstr_fd("Command not found", 2);
	if (str[0] != 0)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n", 2);
	if (cod_exit == 0)
		exit(cod_exit);
	else
		exit(EXIT_FAILURE);
}