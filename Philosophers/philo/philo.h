/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:18:43 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/13 10:44:24 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h>
# include <sys/time.h>
# include <limits.h>

long long int	ft_atoilong(const char *nptr);

typedef struct s_node
{
	long int	num_of_phil;
	long int	time_to_die;
	long int	time_to_sleep;
	long int	time_to_eat;
	long int	num_of_eat;
	long int	*fork;
	long int	i;
	pthread_t	*philo;
	long int	meals_counter;
	long int	last_food;
	long int	start_time;
}			t_node;

void	tmp_fun(t_node node);

#endif
