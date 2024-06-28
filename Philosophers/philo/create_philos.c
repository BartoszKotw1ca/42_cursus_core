/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:18:29 by bkotwica          #+#    #+#             */
/*   Updated: 2024/06/28 13:11:23 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	tmp_mon(t_node **node, long int timee, int p, int i)
{
	int	j;

	j = -1;
	while (++ j < p)
		if (node[j]->meals_counter[j] != node[j]->num_of_eat)
			break ;
	if (j == p)
		return (1);
	if ((timee - node[i]->last_food[i]) > node[i]->time_to_die
		&& node[i]->is_eating == 0)
	{
		print_status(node[i], i + 1, "died", RED);
		i = 0;
		while (i < node[0]->num_of_phil)
			pthread_mutex_lock(&node[i++]->print_mutex);
		return (1);
	}
	return (0);
}

void	*monitoring_one(void *arg)
{
	t_node		**node;
	int			i;
	long int	time;
	long int	p;
	int			j;

	node = (t_node **)arg;
	p = node[0]->num_of_phil;
	i = 0;
	while (i < p)
	{
		usleep(5000);
		time = get_time();
		j = -1;
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
	phil_nodes = malloc(sizeof(t_node *) * node->num_of_phil);
	while (node->i < node->num_of_phil)
	{
		phil_nodes[node->i] = malloc(sizeof(t_node));
		*phil_nodes[node->i] = *node;
		phil_nodes[node->i]->id = node->i + 1;
		phil_nodes[node->i]->dead1 = 0;
		pthread_create(&node->philo[node->i], NULL,
			philo_routine, phil_nodes[node->i]);
		node->i ++;
	}
	pthread_create(&node->check_mutex, NULL,
		monitoring_one, phil_nodes);
	pthread_join(node->check_mutex, NULL);
	node->i = 0;
	while (node->i < node->num_of_phil)
		if (pthread_detach(node->philo[node->i ++]) != 0)
			printf("Something went wrong!!!\n");
	node->i = 0;
	while (node->i < node->num_of_phil)
		free(phil_nodes[node->i++]);
	free(phil_nodes);
}
