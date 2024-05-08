/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:30:24 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/08 10:21:26 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	tmp_fun(t_node node)
{
	node.i = 0;
	while (node.i < node.num_of_phil)
	{
		if (node.i % 2 != 0)
			printf("tak\n");
		node.i ++;
	}
	printf("%d", INT_MAX);
}
