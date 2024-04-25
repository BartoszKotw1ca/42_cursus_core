/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:29:25 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/06 11:29:13 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_Node	*create_node_list(char **list)
{
	int		i;
	t_Node	*head;
	t_Node	*current;
	t_Node	*new_node;

	head = NULL;
	current = NULL;
	i = 0;
	while (list[i])
	{
		new_node = malloc(sizeof(t_Node));
		if (new_node == NULL)
			return (NULL);
		new_node->value = ft_atoi(list[i ++]);
		new_node->next = NULL;
		new_node->previous = current;
		if (head == NULL)
		{
			head = new_node;
			current = head;
		}
		current->next = new_node;
		current = current->next;
	}
	return (head);
}

void	s(t_Node **node)
{
	t_Node	*tmp;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	tmp = (*node)->next;
	(*node)->next = tmp->next;
	tmp->next = *node;
	(*node)->previous = tmp;
	if ((*node)->next != NULL)
		(*node)->next->previous = *node;
	*node = tmp;
	(*node)->previous = NULL;
}

void	p(t_Node **node1, t_Node **node2)
{
	t_Node	*tmp;

	if (*node1 == NULL)
		return ;
	tmp = *node1;
	(*node1) = (*node1)->next;
	if (*node1 != NULL)
		(*node1)->previous = NULL;
	(tmp)->next = *node2;
	if (*node2 != NULL)
		(*node2)->previous = tmp;
	*node2 = tmp;
}

void	r(t_Node **node)
{
	t_Node	*tmp;
	t_Node	*ftmp;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	tmp = *node;
	ftmp = (*node)->next;
	(*node) = (*node)->next;
	(*node)->previous = NULL;
	while ((*node)->next)
		*node = (*node)->next;
	(*node)->next = tmp;
	tmp->previous = (*node);
	tmp->next = NULL;
	*node = ftmp;
}

void	rr(t_Node **node)
{
	t_Node	*first;
	t_Node	*last;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	first = *node;
	while ((*node)->next)
		*node = (*node)->next;
	last = *node;
	if (last->previous)
		last->previous->next = NULL;
	last->previous = NULL;
	last->next = first;
	first->previous = last;
	*node = last;
}
