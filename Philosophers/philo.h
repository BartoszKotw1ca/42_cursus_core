/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:18:43 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/02 15:35:59 by bkotwica         ###   ########.fr       */
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
	int		num_of_phil;
	int		time_to_die;
	int		time_to_sleep;
	int		time_to_eat;
}			t_node;

#endif
