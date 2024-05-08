/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:18:43 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/08 10:19:00 by bkotwica         ###   ########.fr       */
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
	long long int	num_of_phil;
	long long int	time_to_die;
	long long int	time_to_sleep;
	long long int	time_to_eat;
	long long int	num_of_eat;
	long long int	*fork;
	long long int	i;
	pthread_t		*philo;
	int				meals_counter;
	long long int		last_food;	
}			t_node;

void	tmp_fun(t_node node);

#endif
