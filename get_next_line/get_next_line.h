/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:53:48 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/19 19:39:27 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}					g_list;

t_list	*find_last_node(t_list *list);
int		is_newline(t_list *list);
int		len_to_newline(t_list *list);
void	dealloc(t_list **list, t_list *clean_node, char *buffer);
void	polish_list(t_list **list);
void	copy_str(t_list *list, char *str);
void	append(t_list **list, char *buffer);
void	create_list(t_list **list, int fd);
char	*get_line(t_list *list);
char	*get_next_line(int fd);

#endif
