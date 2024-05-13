/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:22:47 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/13 12:04:28 by bkotwica         ###   ########.fr       */
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
	for (int i = 0; i < 1000000; i ++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	// printf("ARG passed to routine %d\n", *(int *)arg);
	free(arg);
	// free(value);
	return ((void *) value);
}

void	exit_message(const char *s)
{
	printf("ERROR: %s", s);
	exit(0);
}

int	check_data(char **argv)
{
	long int	tmp;
	int			i;

	i = 0;
	while (argv[i])
	{
		tmp = ft_atoilong(argv[i]);
		if (tmp > INT_MAX)
			exit_message("Argument is too big!");
		if (tmp < 1)
			exit_message("Argument is too small!");
		i ++;
	}
	return (0);
}

void	write_data(t_node *node, char **argv, int argc)
{
	node->num_of_phil = ft_atoilong(argv[1]);
	node->fork = malloc(sizeof(int) * node->num_of_phil);
	node->time_to_die = ft_atoilong(argv[2]) * 1000;
	node->time_to_eat = ft_atoilong(argv[3]) * 1000;
	node->time_to_sleep = ft_atoilong(argv[4]) * 1000;
	node->num_of_eat = -1;
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
		exit_message("Malloc for philo dumped!");
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
	printf("%d", *res);
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
	long int	end;

	node.start_time = get_time();
	if (argc != 6 && argc != 5)
		exit_message("Too many arguments!");
	if (check_data(argv + 1))
		exit_message("Incorrect arguments!");
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
		// usleep(1234000);
		end = get_time();
		printf("--%ld--\n", end - node.start_time);
	}
	printf("%lld", mails);
	// tmp_fun(node);
	free(node.fork);
	pthread_mutex_destroy(&mutex);
	printf("Num of phil: %ld\nTime to die: %ld\n\
Time to eat: %ld\nTime to sleep: %ld\nNum of eat: %ld\n"
, node.num_of_phil, node.time_to_die, node.time_to_eat
, node.time_to_sleep, node.num_of_eat);
}
