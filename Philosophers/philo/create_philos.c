/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:18:29 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/01 15:57:04 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	tmp_mon(t_node **node, long int timee, int p, int i)
{
	int	j;

	j = -1;
	while (++ j < p)
	{
		pthread_mutex_lock(node[j]->num_of_e);
		pthread_mutex_lock(&node[j]->meals_count[j]);
		if (node[j]->meals_counter[j] != node[j]->num_of_eat)
		{
			pthread_mutex_unlock(&node[j]->meals_count[j]);
			pthread_mutex_unlock(node[j]->num_of_e);
			break ;
		}
	}
	if (j == p)
		return (1);
	pthread_mutex_lock(&node[i]->last_fod[i]);
	pthread_mutex_lock(node[i]->time_to_di);
	pthread_mutex_lock(node[i]->is_eat);
	if ((timee - node[i]->last_food[i]) > node[i]->time_to_die
		&& node[i]->is_eating == 0)
	{
		pthread_mutex_lock(node[0]->print_mutex);
		print_status(node[i], i + 1, "died", RED);
		usleep(500000);
		return (1);
	}
	pthread_mutex_unlock(&node[i]->last_fod[i]);
	pthread_mutex_unlock(node[i]->time_to_di);
	pthread_mutex_unlock(node[i]->is_eat);
	return (0);
}

void	*monitoring_one(void *arg)
{
	t_node		**node;
	int			i;
	long int	time;
	long int	p;

	node = (t_node **)arg;
	p = node[0]->num_of_phil;
	i = 0;
	while (i < p)
	{
		usleep(5000);
		time = get_time();
		if (tmp_mon(node, time, p, i))
			return (NULL);
		i ++;
		i %= p;
		usleep(500);
	}
	return (NULL);
}

void	create_philos(t_node *node)
{
	t_node	**phil_nodes;

	node->i = 0;
	int i = 0;
	phil_nodes = malloc(sizeof(t_node *) * node->num_of_phil);
	while (i < node->num_of_phil)
	{
		phil_nodes[i] = malloc(sizeof(t_node));
		*phil_nodes[i] = *node;
		phil_nodes[i]->id = i + 1;
		phil_nodes[i]->dead1 = 0;
		phil_nodes[i]->num_of_e = node->num_of_e;
		phil_nodes[i]->time_to_di = node->time_to_di;
		phil_nodes[i]->print_mutex = node->print_mutex;
		pthread_create(&node->philo[i], NULL,
			philo_routine, phil_nodes[i]);
		i ++;
	}
	pthread_create(&node->check_mutex, NULL,
		monitoring_one, phil_nodes);
	pthread_join(node->check_mutex, NULL);
	i = 0;
	while (i < node->num_of_phil)
		if (pthread_detach(node->philo[i ++]) != 0)
			printf("Something went wrong!!!\n");
	i = 0;
	while (i < node->num_of_phil)
		free(phil_nodes[i++]);
	free(phil_nodes);
}
