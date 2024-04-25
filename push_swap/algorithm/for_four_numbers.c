/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_four_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 08:56:43 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/09 11:08:10 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	for_four_numbers(t_Node **node, int counter_el)
{
	int		min;
	t_Node	*listb;

	listb = NULL;
	min = min_in_list(node);
	while (listb == NULL)
	{
		helper_a(counter_el, node, min);
		counter_el --;
		p(node, &listb);
		ft_printf("pb\n");
	}
	for_three_numbers(node, max_in_list(node));
	p(&listb, node);
	ft_printf("pa\n");
	free(listb);
}
