/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_one.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:06:39 by bkotwica          #+#    #+#             */
/*   Updated: 2024/06/27 15:25:16 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	for_one_phil(t_node *node)
{
	printf("0 1 has taken a fork\n");
	usleep(node->time_to_die * 1000);
	printf("%lld 1 died\n", get_time() - node->start_time);
	free_data(node);
	free(node->last_food);
	free(node->dead);
	exit(0);
}
