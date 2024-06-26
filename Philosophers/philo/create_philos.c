/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:18:29 by bkotwica          #+#    #+#             */
/*   Updated: 2024/06/26 16:11:19 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philos(t_node *node)
{
	t_node	**phil_nodes;

	node->i = 0;
	phil_nodes = malloc(sizeof(t_node *) * node->num_of_phil);
	while (node->i < node->num_of_phil)
	{
		phil_nodes[node->i] = malloc(sizeof(t_node));
		*phil_nodes[node->i] = *node;
		phil_nodes[node->i]->id = node->i + 1;
		phil_nodes[node->i]->dead = node->dead;
		pthread_create(&node->philo[node->i], NULL,
			philo_routine, phil_nodes[node->i]);
		node->i ++;
	}
	node->i = 0;
	while (node->i < node->num_of_phil)
		pthread_join(node->philo[node->i ++], NULL);
	node->i = 0;
	while (node->i < node->num_of_phil)
		free(phil_nodes[node->i++]);
	free(phil_nodes);
}
