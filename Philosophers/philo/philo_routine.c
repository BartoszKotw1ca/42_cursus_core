/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:19:39 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/02 13:49:14 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	tmp_eating(t_node *node, int right_fork, int left_fork)
{
	if (node->id % 2 == 0)
	{
		usleep(500);
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

void	write_var(t_node *node, int right_fork, int left_fork)
{
	tmp_eating(node, right_fork, left_fork);
	print_status(node, node->id, "is eating", GREEN);
	pthread_mutex_lock(node->is_eat);
	node->is_eating = 1;
	pthread_mutex_unlock(node->is_eat);
	pthread_mutex_lock(&node->last_fod[node->id - 1]);
	node->last_food[node->id - 1] = get_time();
	pthread_mutex_unlock(&node->last_fod[node->id - 1]);
	usleep(node->time_to_eat);
	pthread_mutex_lock(node->is_eat);
	node->is_eating = 0;
	pthread_mutex_unlock(node->is_eat);
	pthread_mutex_lock(&node->meals_count[node->id - 1]);
	node->meals_counter[node->id - 1]++;
	pthread_mutex_unlock(&node->meals_count[node->id - 1]);
	pthread_mutex_unlock(&node->forks[left_fork]);
	pthread_mutex_unlock(&node->forks[right_fork]);
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
	write_var(node, right_fork, left_fork);
	return (1);
}

void	*while_loop(t_node *node)
{
	while (node->num_of_eat == -1
		|| node->meals_counter[node->id - 1] < node->num_of_eat)
	{
		pthread_mutex_lock(node->deadd);
		if (node->dead1 == 1)
		{
			pthread_mutex_unlock(node->deadd);
			return (NULL);
		}
		pthread_mutex_unlock(node->deadd);
		if (node->id % 2 == 0)
			usleep(500);
		eating(node);
		print_status(node, node->id, "is sleeping", MAGENTA);
		usleep(node->time_to_sleep);
		print_status(node, node->id, "is thinking", CYAN);
		usleep(1);
	}
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_node	*node;

	node = (t_node *) arg;
	usleep(500);
	pthread_mutex_lock(node->is_eat);
	node->is_eating = 0;
	pthread_mutex_unlock(node->is_eat);
	pthread_mutex_lock(&node->meals_count[node->id - 1]);
	node->meals_counter[node->id - 1] = 0;
	pthread_mutex_unlock(&node->meals_count[node->id - 1]);
	pthread_mutex_lock(&node->last_fod[node->id - 1]);
	node->last_food[node->id - 1] = get_time();
	pthread_mutex_unlock(&node->last_fod[node->id - 1]);
	while_loop(node);
	return (NULL);
}
