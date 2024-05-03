/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:22:47 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/03 16:33:00 by bkotwica         ###   ########.fr       */
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

// int	main(void)
// {
// 	pthread_t	t[9];
// 	int		*res;
// 	int		sum = 0;
// 	int		i = 0;
// 	pthread_mutex_init(&mutex, NULL);
// 	for (i = 0; i <= 9; i ++)
// 	{
// 		int	*tmp = malloc(sizeof(int));
// 		*tmp = i;
// 		if (pthread_create(&t[i], NULL, &routine, tmp) != 0)
// 			return (0);
// 	}
// 	for (i = 0; i <= 9; i ++)
// 	{
// 		if (pthread_join(t[i], (void **) &res) != 0)
// 			return (0);
// 		sum += *res;
// 	}
// 	pthread_mutex_destroy(&mutex);
// 	printf("Mails: %lld\nValue from threads: %d\nSum from the threads: %d\n", mails, *res, sum);
// 	return (9);
// }

void	exit_message()
{
	perror("The arguments should look like:\n\
./philo \
number_of_philosophers time_to_die time_to_eat \
time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n");
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
		if (tmp > 2147483647 || tmp < 1)
			return (1);
		i ++;
	}
	return (0);
}

void	write_data(t_node *node, char **argv, int argc)
{
	node->num_of_phil = ft_atoilong(argv[1]);
	node->time_to_die = ft_atoilong(argv[2]);
	node->time_to_eat = ft_atoilong(argv[3]);
	node->time_to_sleep = ft_atoilong(argv[4]);
	node->num_of_eat = 10;
	// node->philo = malloc(sizeof(pthread_t) * node->num_of_phil);
	if (argc == 6)
		node->num_of_eat = ft_atoilong(argv[5]);
}

int	main(int argc, char **argv)
{
	t_node		node;
	int			*res;
	pthread_t	*t;
	if (argc != 6 && argc != 5)
		exit_message();
	if (check_data(argv + 1))
		exit_message();
	write_data(&node, argv, argc);
	t = malloc(sizeof(int) * node.num_of_phil);
	int	i = 0;
	for (i = 0; i < 2; i ++)
	{
		int	*tmp = malloc(sizeof(int));
		*tmp = i;
		if (pthread_create(&t[i], NULL, &routine, tmp) != 0)
			return (0);
	}
	for (i = 0; i < 2; i ++)
	{
		if (pthread_join(t[i], (void **) &res) != 0)
			return (0);
		free(res);
	}
	i = 0;
	// while (i < node.num_of_phil)
		// free(&t[i ++]);
	printf("Num of phil: %d\nTime to die: %d\n\
Time to eat: %d\nTime to sleep: %d\nNum of eat: %d\n"
, node.num_of_phil, node.time_to_die, node.time_to_eat
, node.time_to_sleep, node.num_of_eat);
}
