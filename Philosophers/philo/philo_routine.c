/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:19:39 by bkotwica          #+#    #+#             */
/*   Updated: 2024/06/28 11:35:08 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	tmp_eating(t_node *node, int right_fork, int left_fork)
{
	if (node->id % 2 == 0)
	{
		usleep(50);
		pthread_mutex_lock(&node->forks[right_fork]);
		print_status(node, node->id, "has taken a fork", CYAN);
		pthread_mutex_lock(&node->forks[left_fork]);
		print_status(node, node->id, "has taken a fork", CYAN);
	}
	else
	{
		usleep(500);
		pthread_mutex_lock(&node->forks[left_fork]);
		print_status(node, node->id, "has taken a fork", BLUE);
		pthread_mutex_lock(&node->forks[right_fork]);
		print_status(node, node->id, "has taken a fork", BLUE);
	}
}

int	eating(t_node *node)
{
	int	left_fork;
	int	right_fork;
	int	id;

	id = node->id - 1;
	left_fork = id;
	right_fork = (id % node->num_of_phil) - 1;
	if (right_fork < 0)
		right_fork = id + 1;
	if (left_fork == 0)
		right_fork = node->num_of_phil - 1;
	if (node->dead1 == 1)
		exit(0);
	tmp_eating(node, right_fork, left_fork);
	print_status(node, node->id, "is eating", GREEN);
	node->is_eating = 1;
	usleep(node->time_to_eat);
	node->last_food[node->id - 1] = get_time();
	node->is_eating = 0;
	node->meals_counter[node->id - 1]++;
	pthread_mutex_unlock(&node->forks[left_fork]);
	pthread_mutex_unlock(&node->forks[right_fork]);
	return (1);
}

void	*philo_routine(void *arg)
{
	t_node	*node;

	node = (t_node *) arg;
	node->is_eating = 0;
	node->meals_counter[node->id - 1] = 0;
	node->last_food[node->id - 1] = get_time();
	while (node->num_of_eat == -1
		|| node->meals_counter[node->id - 1] < node->num_of_eat)
	{
		if (node->id % 2 == 0)
			usleep(50);
		if (eating(node) == 0)
			exit(1);
		print_status(node, node->id, "is sleeping", MAGENTA);
		usleep(node->time_to_sleep);
		print_status(node, node->id, "is thinking", CYAN);
		usleep(1);
		if (node->dead1 == 1)
			exit(0);
	}
	return (NULL);
}
