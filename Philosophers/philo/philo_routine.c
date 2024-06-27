/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:19:39 by bkotwica          #+#    #+#             */
/*   Updated: 2024/06/27 16:36:24 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_die(t_node *node)
{
	long int	curr_time;

	curr_time = get_time();
	// printf("id: %ld czas: %ld %ld %ld %ld\n", node->id, (curr_time - node->last_food[node->id - 1]), node->time_to_die, node->last_food[node->id - 1], curr_time);
	// printf("czas: %ld\n %ld\n", (curr_time - node->last_food[node->id - 1]), node->time_to_die);
	if ((curr_time - node->last_food[node->id - 1]) > node->time_to_die)
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
	int	id;

	id = node->id - 1;
	// printf("%d", id);
	left_fork = id;
	right_fork = (id % node->num_of_phil) - 1;
	if (right_fork < 0)
		right_fork = id + 1;
	if (left_fork == 0)
		right_fork = node->num_of_phil - 1;
	// printf("id: %d, l: %d, p: %d\n", id, left_fork, right_fork);
	// printf("%ld\n", node->id);
	if (check_if_die(node) == 0)
		return (0);
	else if (node->id % 2 == 0)
	{
		// printf("w if: %d %d %ld\n", left_fork, right_fork, node->id);
		usleep(50);
		pthread_mutex_lock(&node->forks[right_fork]);
		print_status(node, node->id, "has taken a fork", CYAN);
		pthread_mutex_lock(&node->forks[left_fork]);
		print_status(node, node->id, "has taken a fork", CYAN);
	}
	else
	{
		// printf("w else: %d %d %ld\n", left_fork, right_fork, node->id);
		usleep(50);
		pthread_mutex_lock(&node->forks[left_fork]);
		print_status(node, node->id, "has taken a fork", BLUE);
		pthread_mutex_lock(&node->forks[right_fork]);
		print_status(node, node->id, "has taken a fork", BLUE);
	}
	print_status(node, node->id, "is eating", GREEN);
	node->is_eating = 1;
	usleep(node->time_to_eat);
	// printf("id: %ld\n",node->id);
	node->last_food[node->id - 1] = get_time();
	node->is_eating = 0;
	// printf("time: %ld\n", node->last_food[node->id - 1]);
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
	}
	return (NULL);
}
