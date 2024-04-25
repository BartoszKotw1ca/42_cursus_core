/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:18:53 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/09 11:00:13 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// its just check how many times it should rotate 
// the stack a
void	helper_a(int counter_el, t_Node **node, int target)
{
	int	j;

	if ((counter_el / 2) < (current_pos(node, target)))
	{
		j = counter_el - (current_pos(node, target));
		while (j-- > 0)
		{
			ft_printf("rra\n");
			rr(node);
		}
	}
	else
	{
		j = (current_pos(node, target));
		while (j-- > 0)
		{
			ft_printf("ra\n");
			r(node);
		}
	}
}

// its juts check how many times it should rotate
// the stack b
void	helper_b(int counter_el, t_Node **listb, int target)
{
	int	j;

	if ((counter_el / 2) < (current_pos(listb, target)))
	{
		j = counter_el - (current_pos(listb, target));
		while (j-- > 0)
		{
			ft_printf("rrb\n");
			rr(listb);
		}
	}
	else
	{
		j = (current_pos(listb, target));
		while (j-- > 0)
		{
			ft_printf("rb\n");
			r(listb);
		}
	}
}

// that funcion pushes elements from a to b unless
// counter_el so unless in stack a is more than 3 elements
void	push_nodes_to_b(t_Node **node, t_Node **listb, int el_a)
{
	t_Node	*tmp;
	int		target;
	int		el_b;

	el_b = 2;
	while (el_a -- >= 3)
	{
		tmp = node_to_push(node, listb);
		helper_a(el_a + 2, node, tmp->value);
		target = search_for_lower_value(tmp, listb);
		helper_b(el_b, listb, target);
		p(node, listb);
		ft_printf("pb\n");
		el_b ++;
	}
}

// it push back the nodes from b to stack a
void	push_nodes_to_a(t_Node **node, t_Node **listb)
{
	int	target;
	int	counter_el;

	counter_el = num_in_ll(node) + 1;
	while (*listb)
	{
		target = search_for_maks_value(*listb, node);
		helper_a(counter_el, node, target);
		counter_el ++;
		p(listb, node);
		ft_printf("pa\n");
	}
}

void	algorithm(t_Node **node, int counter_el)
{
	t_Node	*listb;

	listb = NULL;
	counter_el -= 2;
	push_first_two(node, &listb);
	push_nodes_to_b(node, &listb, num_in_ll(node));
	for_three_numbers(node, max_in_list(node));
	push_nodes_to_a(node, &listb);
	put_the_min(node, num_in_ll(node) + 1);
}
