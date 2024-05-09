/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:42:23 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/09 11:53:24 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process(t_struct node, int status, int sta1)
{
	if (status == 0 && sta1 != -1)
	{
		dup2(node.infile, STDIN_FILENO);
		dup2(node.fd[1], STDOUT_FILENO);
		close(node.fd[0]);
		close(node.fd[1]);
		if (node.path1)
			if (execve(node.path1, node.cmd1, node.envp) == -1)
				exit_message(node, 1);
	}
	else if ((sta1 != -1 || status != 0) && node.path2)
	{
		dup2(node.fd[0], STDIN_FILENO);
		dup2(node.outfile, STDOUT_FILENO);
		close(node.fd[0]);
		close(node.fd[1]);
		close(node.infile);
		if (execve(node.path2, node.cmd2, node.envp) == -1)
			exit_message(node, 1);
	}
}

int	execute(t_struct node)
{
	int	status;

	if (pipe(node.fd) == -1)
		return (1);
	node.outfile = open(node.argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	node.infile = open(node.argv[1], O_RDONLY);
	if (node.infile == -1)
		perror("ERROR");
	status = fork();
	process(node, status, node.infile);
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

	node.argv = argv;
	node.envp = envp;
	node.argc = argc;
	node.path1 = NULL;
	node.path2 = NULL;
	if (argc != 5)
		exit_message(node, 0);
	if (ft_strlen(argv[4]) == 0)
		exit_message(node, 0);
	node.cmd1 = ft_split(node.argv[2], ' ');
	node.cmd2 = ft_split(node.argv[3], ' ');
	if (node.cmd1[0] != NULL)
		node.path1 = find_path(node, node.cmd1[0]);
	if (node.cmd2[0] != NULL)
		node.path2 = find_path(node, node.cmd2[0]);
	if (argc == 5)
		execute(node);
	else
		exit_message(node, 1);
	return (0);
}

// "grep test" "wc -l" outfile.txt
// function execve give an 0 0 to outfile when
// ./pipex "infile" "" "wc -l" "outfile"
// ➜  pipex git:(main) ✗ cat outfile  
// 0
// 0
