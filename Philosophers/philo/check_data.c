/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:43:04 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/14 11:46:36 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_data(char **argv, int argc)
{
	long int	tmp;
	int			i;

	if (argc != 6 && argc != 5)
		exit_message("Incorrect number of arguments!");
	i = 0;
	while (argv[i])
	{
		tmp = ft_atoilong(argv[i]);
		if (tmp > INT_MAX)
			exit_message("Argument is too big!");
		if (tmp < 1)
			exit_message("Argument is too small!");
		i ++;
	}
	return (0);
}
