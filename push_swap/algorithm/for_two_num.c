/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_two_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:22:55 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/07 10:02:26 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	for_two_numbers(t_Node **node)
{
	int	i;

	i = 0;
	if ((*node)->value > (*node)->next->value)
	{
		s(node);
		ft_printf("sa\n");
		i ++;
	}
	return (i);
}
