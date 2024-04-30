/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:42:23 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/29 18:15:00 by bkotwica         ###   ########.fr       */
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

int	function(char **argv)
{
	int	fd[2];
	int	status;
	int	outfile;
	int	infile;

	outfile= open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	infile = open(argv[1], O_RDONLY);
	char	**cmd1 = ft_split(argv[2], ' ');
	char	**cmd2 = ft_split(argv[3], ' ');
	char	*com1[] = {add_str("/usr/bin/", cmd1[0]), cmd1[0], cmd1[1], NULL};
	// free(com1[1]);
	char	*com2[] = {add_str("/usr/bin/", cmd2[0]), cmd2[0], cmd2[1], NULL};
	if (pipe(fd) == -1)
		return (1);
	status = fork();
	if (status == 0)
	{
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(com1[0], com1 + 1, NULL);
		exit(0);
		free_mallocs(cmd1);
		free_mallocs(cmd2);
		// exit(0);
	}
	else
	{
		// exit(0);
		wait(NULL);
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(com2[0], com2 + 1, NULL);
		free_mallocs(cmd1);
		free_mallocs(cmd2);
		// free(com1[1]);
		// free(com2[1]);
	}
	close(outfile);
	close(infile);
	return (0);
}

int	main(int arc, char **argv)
{
	if (arc == 5)
		function(argv);
	return (0);
}
