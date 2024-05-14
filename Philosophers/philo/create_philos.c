/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:18:29 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/14 13:18:54 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philos(t_node *node)
{
	t_node	*phil_node;

	node->i = -1;
	while (node->i++ < node->num_of_phil)
	{
		phil_node = malloc(sizeof(t_node));
		*phil_node = *node;
		phil_node->id = node->i;
		pthread_create(&node->philo[node->i], NULL,
			philo_routine, phil_node);
		free(phil_node);
	}
	node->i = -1;
	while (node->i++ < node->num_of_phil)
		pthread_join(node->philo[node->i], NULL);
}
