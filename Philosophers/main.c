/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:22:47 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/02 13:59:16 by bkotwica         ###   ########.fr       */
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
	// for (int i = 0; i < 10000000; i ++)
	// {
	// 	pthread_mutex_lock(&mutex);
	// 	mails++;
	// 	pthread_mutex_unlock(&mutex);
	// }
	printf("ARG passed to routine %d\n", *(int *)arg);
	return ((void *) value);
}

int	main(void)
{
	pthread_t	t[9];
	int		*res;
	int		sum = 0;
	int		i = 0;
	for (i = 0; i <= 9; i ++)
	{
		int	*tmp = malloc(sizeof(int));
		*tmp = i;
		if (pthread_create(&t[i], NULL, &routine, tmp) != 0)
			return (0);
	}
	for (i = 0; i <= 9; i ++)
	{
		if (pthread_join(t[i], (void **) &res) != 0)
			return (0);
		sum += *res;
	}
	printf("Mails: %lld\nValue from threads: %d\nSum from the threads: %d\n", mails, *res, sum);
	return (9);
}
