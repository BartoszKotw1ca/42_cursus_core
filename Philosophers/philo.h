/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:18:43 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/03 15:19:38 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>


long long int	ft_atoilong(const char *nptr);

typedef struct s_node
{
	int			num_of_phil;
	int			time_to_die;
	int			time_to_sleep;
	int			time_to_eat;
	int			num_of_eat;
	pthread_t	*philo;
	
}			t_node;

#endif
