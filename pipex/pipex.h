/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:41:16 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/30 15:19:16 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "mylibft/mylibft.h"
# include <stdio.h> // perror, 
# include <string.h> // strerror, 
# include <stdlib.h> // malloc, exit, 
# include <sys/wait.h> //
# include <unistd.h> // read, write,
// access, dup, dup2, execve, pipe
# include <fcntl.h> // open, close
# include <sys/types.h> // fork, wait
# include <sys/wait.h> // wait, waitpid

typedef struct s_struct
{
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
	char	**envp;
	char	**argv;
	int		argc;
	char	**paths;
	int		outfile;
	int		infile;
	int		fd[2];
}			t_struct;

void	exit_message(void);
void	free_mallocs(char **list);
char	*add_str(char *str1, char *str2);

#endif
