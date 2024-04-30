/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:42:23 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/30 15:25:12 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process(t_struct node, int status)
{
	if (status == 0)
	{
		dup2(node.infile, STDIN_FILENO);
		dup2(node.fd[1], STDOUT_FILENO);
		close(node.fd[0]);
		close(node.fd[1]);
		if (execve(node.path1, node.cmd1, node.envp) == -1)
			exit_message();
	}
	else
	{
		dup2(node.fd[0], STDIN_FILENO);
		dup2(node.outfile, STDOUT_FILENO);
		close(node.fd[0]);
		close(node.fd[1]);
		execve(node.path2, node.cmd2, node.envp);
	}
}

int	execute(t_struct node)
{
	int	status;

	if (access(node.path1, F_OK) == -1
		|| access(node.path2, F_OK) == -1)
		exit_message();
	if (pipe(node.fd) == -1)
		return (1);
	node.outfile = open(node.argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	node.infile = open(node.argv[1], O_RDONLY);
	if (node.infile == -1)
		exit_message();
	status = fork();
	process(node, status);
	waitpid(status, NULL, 0);
	close(node.outfile);
	close(node.infile);
	return (0);
}

char	*find_path(t_struct node, char *com)
{
	int		i;
	char	*path;
	char	*tmp;

	i = 0;
	while (ft_strnstr(node.envp[i], "PATH", 4) == 0)
		i++;
	node.paths = ft_split(node.envp[i] + 5, ':');
	i = 0;
	while (node.paths[i])
	{
		tmp = add_str(node.paths[i], "/");
		path = add_str(tmp, com);
		if (access(path, F_OK) == 0)
		{
			free(tmp);
			free_mallocs(node.paths);
			return (path);
		}
		free(tmp);
		free(path);
		i ++;
	}
	free_mallocs(node.paths);
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	t_struct	node;

	node.envp = envp;
	node.argv = argv;
	node.argc = argc;
	node.cmd1 = ft_split(node.argv[2], ' ');
	node.cmd2 = ft_split(node.argv[3], ' ');
	node.path1 = find_path(node, node.cmd1[0]);
	node.path2 = find_path(node, node.cmd2[0]);
	printf("%s\n%s\n", node.path1, node.path2);
	// if (argc == 5)
	// 	execute(node);
	// else
	// 	exit_message();
	free_mallocs(node.cmd1);
	free_mallocs(node.cmd2);
	free(node.path1);
	free(node.path2);
	return (0);
}
