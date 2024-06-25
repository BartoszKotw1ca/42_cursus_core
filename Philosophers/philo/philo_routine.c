/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:19:39 by bkotwica          #+#    #+#             */
/*   Updated: 2024/06/25 18:41:40 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_die(t_node *node)
{
	long int	curr_time;

	curr_time = get_time();
	if ((curr_time - node->last_food[node->id]) * 1000 > node->time_to_die)
	{
		print_status(node, node->id, "died");
		pthread_mutex_unlock(&node->forks[node->id - 1]);
		pthread_mutex_unlock(&node->forks[(node->id + 1) % node->num_of_phil - 1]);
		node->died = 1;
		return (0);
	}
	return (1);
}

int	eating(t_node *node)
{
	if (node->died)
		exit(1);
	if (check_if_die(node) == 0)
		return (0);
	else if (node->id % 2 == 0)
	{
		pthread_mutex_lock(&node->forks[(node->id + 1) % node->num_of_phil - 1]);
		print_status(node, node->id, "has taken a fork");
		pthread_mutex_lock(&node->forks[node->id - 1]);
		print_status(node, node->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&node->forks[node->id - 1]);
		print_status(node, node->id, "has taken a fork");
		pthread_mutex_lock(&node->forks[(node->id + 1) % node->num_of_phil - 1]);
		print_status(node, node->id, "has taken a fork");
	}
	print_status(node, node->id, "is eating");
	usleep(node->time_to_eat);
	node->last_food[node->id] = get_time();
	node->meals_counter[node->id] ++;
	pthread_mutex_unlock(&node->forks[node->id -1]);
	pthread_mutex_unlock(&node->forks[(node->id + 1) % node->num_of_phil - 1]);
	return (1);
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
		if (eating(node) == 0)
			exit(1);
		print_status(node, node->id, "is sleeping");
		usleep(node->time_to_sleep);
		print_status(node, node->id, "is thinking");
		usleep(1);
	}
	return (NULL);
}
