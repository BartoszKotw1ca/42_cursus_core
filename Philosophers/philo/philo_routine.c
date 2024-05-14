/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:19:39 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/14 13:23:00 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_node	*node;

	node = (t_node *) arg;
	node->meals_counter[node->id] = 0;
	node->last_food[node->id] = get_time();
	return ((void *) arg);
}
