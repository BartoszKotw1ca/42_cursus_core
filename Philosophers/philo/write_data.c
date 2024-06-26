/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:41:30 by bkotwica          #+#    #+#             */
/*   Updated: 2024/06/26 09:46:17 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_data(t_node *node, char **argv, int argc)
{
	node->num_of_phil = ft_atoilong(argv[1]);
	node->time_to_die = ft_atoilong(argv[2]) * 1000;
	node->time_to_eat = ft_atoilong(argv[3]) * 1000;
	node->time_to_sleep = ft_atoilong(argv[4]) * 1000;
	node->forks = malloc(sizeof(pthread_mutex_t) * node->num_of_phil);
	node->philo = malloc(sizeof(pthread_t) * node->num_of_phil);
	node->meals_counter = malloc(sizeof(long int) * node->num_of_phil);
	node->last_food = malloc(sizeof(long int) * node->num_of_phil);
	node->dead = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(node->dead, NULL);
	if (!node->forks || !node->philo || !node->meals_counter || !node->last_food)
		exit(0);
	node->num_of_eat = -1;
	if (argc == 6)
		node->num_of_eat = ft_atoilong(argv[5]);
	else
		node->num_of_eat = -1;
	pthread_mutex_init(&node->print_mutex, NULL);
	node->i = 0;
	while (node->i < node->num_of_phil)
		pthread_mutex_init(&node->forks[node->i ++], NULL);
}
