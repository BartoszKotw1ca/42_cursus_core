/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:30:24 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/01 13:28:42 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	tmp_fun(t_node node)
{
	node.i = 0;
	while (node.i < node.num_of_phil)
	{
		if (node.i % 2 != 0)
			printf("tak\n");
		node.i ++;
	}
	printf("%d", INT_MAX);
}

long long int	get_time(void)
{
	struct timeval	tmp;

	if (gettimeofday(&tmp, NULL))
		return (0);
	return ((tmp.tv_sec * (long long int) 1000) + (tmp.tv_usec / 1000));
}

void	exit_message(const char *s)
{
	printf("ERROR: %s", s);
	exit(0);
}

void	free_data(t_node *node)
{
	usleep(500);
	node->i = 0;
	while (node->i < node->num_of_phil)
	{
		pthread_mutex_unlock(&node->forks[node->i]);
		pthread_mutex_destroy(&node->forks[node->i ++]);
	}
	pthread_mutex_unlock(node->print_mutex);
	pthread_mutex_destroy(node->print_mutex);
	free(node->forks);
	free(node->philo);
	free(node->last_food);
	free(node->meals_counter);
}

pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;

void	print_status(t_node *node, int id, const char *status, char *color)
{
	pthread_mutex_lock(&print_mutex);
	printf("%s%lld %d %s%s\n", color, get_time() - node->start_time,
		id, status, RESET);
	pthread_mutex_unlock(&print_mutex);
}
