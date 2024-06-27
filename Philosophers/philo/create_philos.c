/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:18:29 by bkotwica          #+#    #+#             */
/*   Updated: 2024/06/27 16:51:40 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void cleanup(t_node *node)
{
	free(node->forks);
	free(node->philo);
	free(node->meals_counter);
	free(node->last_food);
	free(node->dead);
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
		if ((time - node[i]->last_food[i]) > node[i]->time_to_die
			&& node[i]->is_eating == 0)
		{
			print_status(node[i], i + 1, "died", RED);
			return (NULL);
			cleanup(node[0]);
			free(node);
			exit(0);
		}
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
		phil_nodes[node->i]->dead = node->dead;
		pthread_create(&node->philo[node->i], NULL,
			philo_routine, phil_nodes[node->i]);
		node->i ++;
	}
	pthread_create(&node->check_mutex, NULL,
			monitoring_one, phil_nodes);
	node->i = 0;
	while (node->i < node->num_of_phil)
		pthread_join(node->philo[node->i ++], NULL);
	pthread_join(node->check_mutex, NULL);
	node->i = 0;
	while (node->i < node->num_of_phil)
		free(phil_nodes[node->i++]);
	free(phil_nodes);
}

