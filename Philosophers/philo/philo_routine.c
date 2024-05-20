/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:19:39 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/20 12:25:32 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eating(t_node *node)
{
	long int	curr_time;

	if (node->id % 2 == 0)
	{
		pthread_mutex_lock(&node->forks[(node->id + 1) % node->num_of_phil]);
		pthread_mutex_lock(&node->forks[node->id]);
	}
	else
	{
		pthread_mutex_lock(&node->forks[node->id]);
		pthread_mutex_lock(&node->forks[(node->id + 1) % node->num_of_phil]);
	}
	curr_time = get_time();
	if (curr_time - node->last_food[node->id] > node->time_to_die)
	{
		print_status(node, node->id, "died");
		pthread_mutex_unlock(&node->forks[node->id]);
		pthread_mutex_unlock(&node->forks[(node->id + 1) % node->num_of_phil]);
		return NULL;
	}
	print_status(node, node->id, "is eating");
	usleep(node->time_to_eat);
	node->last_food[node->id] = get_time();
	node->meals_counter[node->id] ++;
	pthread_mutex_unlock(&node->forks[node->id]);
	pthread_mutex_unlock(&node->forks[(node->id + 1) % node->num_of_phil]);
	return NULL;
}

void	*philo_routine(void *arg)
{
	t_node	*node;

	node = (t_node *) arg;
	node->meals_counter[node->id] = 0;
	node->last_food[node->id] = get_time();
	while (node->num_of_eat == -1
		|| node->meals_counter[node->id] < node->num_of_eat)
	{
		eating(node);
		print_status(node, node->id, "is thinking");
		usleep(node->time_to_sleep);
		printf("%ld", node->time_to_sleep);
		print_status(node, node->id, "is sleeping");
		usleep(node->time_to_sleep);
		printf("%ld", node->time_to_sleep);
		// exit(0);
	}
	return (NULL);
}
