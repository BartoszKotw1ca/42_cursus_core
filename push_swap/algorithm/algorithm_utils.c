/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:40:21 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/09 10:53:20 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// its only pushes two first node from lista to listb
void	push_first_two(t_Node **node, t_Node **listb)
{
	p(node, listb);
	p(node, listb);
	ft_printf("pb\npb\n");
}

// its helper function, just abs on number
long long int	myabs(long long int nr)
{
	if (nr < 0)
		nr *= -1;
	return (nr);
}

// its check is numer is greater or lower than 0
long long int	check(long long int a, long long int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
		return (myabs(myabs(b) - myabs(a)));
	else
		return (myabs(a) + myabs(b));
}

// it is the helper for push_cost 
// its searching for the lower closest value
int	search_for_lower_value(t_Node *node, t_Node **listb)
{
	long long int	diff;
	long long int	to_retu;
	t_Node			*tmp_a;
	t_Node			*tmp_b;
	t_Node			*tmp_bb;

	tmp_a = node;
	tmp_b = *listb;
	tmp_bb = *listb;
	diff = 9223372036854775807;
	while (tmp_b)
	{
		if ((tmp_b->value < tmp_a->value)
			&& (diff > check(tmp_a->value, tmp_b->value)))
		{
			diff = check(tmp_b->value, tmp_a->value);
			to_retu = tmp_b->value;
		}
		tmp_b = tmp_b->next;
	}
	if (diff == 9223372036854775807)
		to_retu = max_in_list(&tmp_bb);
	return (to_retu);
}

int	search_for_maks_value(t_Node *node, t_Node **listb)
{
	long long int	diff;
	long long int	to_retu;
	t_Node			*tmp_a;
	t_Node			*tmp_b;
	t_Node			*tmp_bb;

	tmp_a = node;
	tmp_b = *listb;
	tmp_bb = *listb;
	diff = 9223372036854775807;
	while (tmp_b)
	{
		if ((tmp_b->value > tmp_a->value)
			&& (diff > check(tmp_b->value, tmp_a->value)))
		{
			diff = check(tmp_b->value, tmp_a->value);
			to_retu = tmp_b->value;
		}
		tmp_b = tmp_b->next;
	}
	if (diff == 9223372036854775807)
		to_retu = min_in_list(&tmp_bb);
	return (to_retu);
}
