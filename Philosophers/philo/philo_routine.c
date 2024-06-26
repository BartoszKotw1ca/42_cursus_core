/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:19:39 by bkotwica          #+#    #+#             */
/*   Updated: 2024/06/26 16:51:43 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_die(t_node *node)
{
	long int	curr_time;

	curr_time = get_time();
	if ((curr_time - node->last_food[node->id - 1]) * 1000 > node->time_to_die)
	{
		print_status(node, node->id, "died", RED);
		pthread_mutex_unlock(&node->forks[node->id - 1]);
		pthread_mutex_unlock(&node->forks[(node->id + 1) % node->num_of_phil]);
		pthread_mutex_lock(node->dead);
		pthread_mutex_lock(&node->print_mutex);
		node->dead1 = 1;
		return (0);
	}
	return (1);
}

int	eating(t_node *node)
{
	int	left_fork;
	int	right_fork;
	// printf("%ld\n", node->id);
	if (check_if_die(node) == 0)
		return (0);
	else if (node->id % 2 == 0)
	{
		left_fork = (node->id + 1) % node->num_of_phil - 1;
		right_fork = node->id - 1;
		printf("w if: %ld %ld\n", (node->id + 1) % node->num_of_phil - 1, node->id - 1);
		// pthread_mutex_lock(&node->forks[(node->id + 1) % node->num_of_phil] - 1);
		pthread_mutex_lock(&node->forks[left_fork]);
		print_status(node, node->id, "has taken a fork", CYAN);
		pthread_mutex_lock(&node->forks[right_fork]);
		print_status(node, node->id, "has taken a fork", CYAN);
	}
	else
	{
		left_fork = node->id;
		right_fork = (node->id + 1) % node->num_of_phil;
		printf("w else: %ld %ld\n", node->id, (node->id + 1) % node->num_of_phil);
		pthread_mutex_lock(&node->forks[node->id]);
		print_status(node, node->id, "has taken a fork", BLUE);
		pthread_mutex_lock(&node->forks[right_fork]);
		print_status(node, node->id, "has taken a fork", BLUE);
	}
	print_status(node, node->id, "is eating", GREEN);
	usleep(node->time_to_eat);
	printf("id: %ld\n",node->id);
	node->last_food[node->id - 1] = get_time();
	printf("time: %ld\n", node->last_food[node->id - 1]);
	node->meals_counter[node->id - 1] ++;
	// return (0);
	pthread_mutex_unlock(&node->forks[left_fork]);
	pthread_mutex_unlock(&node->forks[right_fork]);
	return (1);
}

void	*philo_routine(void *arg)
{
	t_node	*node;

	node = (t_node *) arg;
	node->meals_counter[node->id - 1] = 0;
	node->last_food[node->id - 1] = get_time();
	while (node->num_of_eat == -1
		|| node->meals_counter[node->id - 1] < node->num_of_eat)
	{
		if (eating(node) == 0)
			exit(1);
		print_status(node, node->id, "is sleeping", MAGENTA);
		usleep(node->time_to_sleep);
		print_status(node, node->id, "is thinking", CYAN);
		usleep(1);
	}
	return (NULL);
}
