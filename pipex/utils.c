/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:18:22 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/30 15:18:52 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*add_str(char *str1, char *str2)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = 0;
	len = ft_strlen(str1) + ft_strlen(str2);
	res = malloc(len + 1);
	res[len] = '\0';
	len = 0;
	while (str1[len])
		res[i ++] = str1[len ++];
	len = 0;
	while (str2[len])
		res[i ++] = str2[len ++];
	return (res);
}

void	free_mallocs(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}

void	exit_message(void)
{
	perror("Error\n\
The argument should look like:\n\
./pipex <infile> \"command1\" \"command2\" <outfile> ");
	exit(EXIT_FAILURE);
}
