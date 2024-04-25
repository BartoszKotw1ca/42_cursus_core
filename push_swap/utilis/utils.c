/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:07:17 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/09 14:34:21 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_in_list(t_Node **node)
{
	int		max;
	t_Node	*tmp;

	tmp = *node;
	max = tmp->value;
	while (tmp)
	{
		if (max < tmp->value)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	check_if_sorted_back(t_Node **node)
{
	t_Node	*temp;

	temp = *node;
	while (temp->next)
	{
		if (temp->value < temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_if_sorted(t_Node **node)
{
	t_Node	*temp;

	if (*node == NULL || (*node)->next == NULL)
		return (0);
	temp = *node;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	count_words_split(char const *s, char c)
{
	size_t	counter;
	int		switcher;

	counter = 0;
	while (*s)
	{
		switcher = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			if (switcher == 0)
			{
				counter++;
				switcher = 1;
			}
			s++;
		}
	}
	return (counter);
}

int	count_words(char **list)
{
	int	counter;

	counter = 0;
	while (*list)
	{
		counter ++;
		list ++;
	}
	return (counter);
}
