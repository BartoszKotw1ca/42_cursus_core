/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_three_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:05:44 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/09 09:24:14 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// there it will be max 2 steps
void	for_three_numbers(t_Node **node, int max)
{
	while (!check_if_sorted(node))
	{
		if (check_if_sorted_back(node))
		{
			s(node);
			rr(node);
			ft_printf("sa\nrra\n");
		}
		else if (max == (*node)->value)
		{
			rr(node);
			ft_printf("rra\n");
		}
		else if ((*node)->next->value > (*node)->next->next->value)
		{
			rr(node);
			ft_printf("rra\n");
		}
		else if ((*node)->value > (*node)->next->value)
			for_two_numbers(node);
	}
}
