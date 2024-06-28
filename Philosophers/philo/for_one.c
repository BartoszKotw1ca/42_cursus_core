/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_one.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:06:39 by bkotwica          #+#    #+#             */
/*   Updated: 2024/06/28 13:07:31 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	for_one_phil(t_node *node)
{
	print_status(node, 1, "has taken a fork", YELLOW);
	usleep(node->time_to_die * 1000);
	print_status(node, 1, "died", RED);
	free_data(node);
	exit(0);
}
