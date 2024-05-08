/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:22:47 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/08 13:05:21 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

long long int	mails = 0;
pthread_mutex_t mutex;

void	*routine(void *arg)
{
	int	*value;
	value = malloc(sizeof(int) * 1);
	*value = 1;
	for (int i = 0; i < 10000000; i ++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	printf("ARG passed to routine %d\n", *(int *)arg);
	free(arg);
	// free(value);
	return ((void *) value);
}

void	exit_message()
{	// free(node.philo);

	perror("The arguments should look like:\n\
./philo \
number_of_philosophers time_to_die time_to_eat \
time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n");
	exit(0);
}

int	check_data(char **argv)
{
	long long unsigned int	tmp;
	int			i;

	i = 0;
	while (argv[i])
	{
		tmp = ft_atoilong(argv[i]);
		if (tmp > LONG_MAX || tmp < 1)
			return (1);
		i ++;
	}
	return (0);
}

void	write_data(t_node *node, char **argv, int argc)
{
	node->num_of_phil = ft_atoilong(argv[1]);
	node->fork = malloc(sizeof(int) * node->num_of_phil);
	node->time_to_die = ft_atoilong(argv[2]);
	node->time_to_eat = ft_atoilong(argv[3]);
	node->time_to_sleep = ft_atoilong(argv[4]);
	node->num_of_eat = 10;
	if (argc == 6)
		node->num_of_eat = ft_atoilong(argv[5]);
	else
		node->num_of_eat = -1;
}

int	create_join_threads(t_node node)
{
	int			*res;

	node.philo = malloc(sizeof(pthread_t) * node.num_of_phil);
	if (!node.philo)
		return (1);
	node.i = 0;
	while (node.i < node.num_of_phil)
	{
		int	*tmp = malloc(sizeof(int));
		*tmp = node.i;
		if (pthread_create(&node.philo[node.i], NULL, &routine, tmp) != 0)
			return (2);
		node.i ++;
	}
	node.i = 0;
	while (node.i < node.num_of_phil)
	{
		if (pthread_join(node.philo[node.i], (void **) &res) != 0)
			return (3);
		free(res);
		node.i ++;
	}
	free(node.philo);
	return (0);
}

long long int	get_time(void)
{
	struct timeval	tmp;

	if (gettimeofday(&tmp, NULL))
		return (0);
	return ((tmp.tv_sec * (long long int) 1000) + (tmp.tv_usec / 1000));
}

// struct timeval time; time.tv_sec - sec from Jan 1970
// 1s = 1000 miliseconds
// 1 mili = 1000 micro
// usleep(micros);
// data race mutex
int	main(int argc, char **argv)
{
	t_node		node;
	long long int	start;
	long long int	end;

	start = get_time();
	if (argc != 6 && argc != 5)
		exit_message();
	if (check_data(argv + 1))
		exit_message();
	write_data(&node, argv, argc);
	pthread_mutex_init(&mutex, NULL);
	if (create_join_threads(node))
	{
		free(node.philo);
		exit (1);
	}
	node.i = 0;
	while (node.i++ < 10)
	{
		usleep(1234000);
		end = get_time();
		printf("--%lld--\n", end - start);
	}
	tmp_fun(node);
	free(node.fork);
	pthread_mutex_destroy(&mutex);
// 	printf("Num of phil: %lld\nTime to die: %lld\n\
// Time to eat: %lld\nTime to sleep: %lld\nNum of eat: %lld\n %lld"
// , node.num_of_phil, node.time_to_die, node.time_to_eat
// , node.time_to_sleep, node.num_of_eat, end - start);
}
