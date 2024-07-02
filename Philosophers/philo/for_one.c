/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_one.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:06:39 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/02 19:20:34 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	for_one_phil(t_node *node)
{
	node->id = 1;
	print_status(node, 1, "has taken a fork", YELLOW);
	usleep(node->time_to_die * 1000);
	print_status(node, 1, "died", RED);
	free_data(node);
	exit(0);
}
