/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:22:47 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/14 13:19:54 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// struct timeval time; time.tv_sec - sec from Jan 1970
// 1s = 1000 miliseconds
// 1 mili = 1000 micro
// usleep(micros);
// data race mutex
int	main(int argc, char **argv)
{
	t_node		node;

	check_data(argv + 1, argc);
	write_data(&node, argv, argc);
	node.start_time = get_time();
	create_philos(&node);
	free_data(&node);
// 	printf("Num of phil: %ld\nTime to die: %ld\n\
// Time to eat: %ld\nTime to sleep: %ld\nNum of eat: %ld\n"
// , node.num_of_phil, node.time_to_die, node.time_to_eat
// , node.time_to_sleep, node.num_of_eat);
}
