/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:18:43 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/14 13:20:18 by bkotwica         ###   ########.fr       */
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

typedef struct s_node
{
	long int		id;
	long int		num_of_phil;
	long int		time_to_die;
	long int		time_to_sleep;
	long int		time_to_eat;
	long int		num_of_eat;
	long int		i;
	long int		start_time;
	long int		*meals_counter;
	long int		*last_food;
	pthread_mutex_t	*forks;
	pthread_t		*philo;
	pthread_mutex_t	print_mutex;
}			t_node;

// Utils
void			tmp_fun(t_node node);
long long int	get_time(void);
void			exit_message(const char *s);
void			free_data(t_node *node);

// Write_data
void			write_data(t_node *node, char **argv, int argc);

// Check_data
int				check_data(char **argv, int argc);

// ft_atoilong
long long int	ft_atoilong(const char *nptr);

// create_philos
void	create_philos(t_node *node);

// philo_routine
void	*philo_routine(void *arg);
#endif
