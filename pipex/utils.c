/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:18:22 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/08 13:51:15 by bkotwica         ###   ########.fr       */
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

void	exit_message(t_struct node, bool a)
{
	perror("Error");
	if (a == 1)
	{
		free_mallocs(node.cmd1);
		free_mallocs(node.cmd2);
		free(node.path1);
		free(node.path2);
	}
	exit(EXIT_FAILURE);
}
