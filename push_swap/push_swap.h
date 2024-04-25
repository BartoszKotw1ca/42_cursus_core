/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:30:59 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/09 11:04:05 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "mylibft/mylibft.h"
# include <stdlib.h>

typedef struct Node
{
	struct Node	*next;
	struct Node	*previous;
	int			value;
}		t_Node;

long long int	ft_atoilong(const char *nptr);
long long int	myabs(long long int nr);
long long int	check(long long int a, long long int b);
int				check_all(char **list);
t_Node			*create_node_list(char **list);
void			s(t_Node **node);
void			p(t_Node **node1, t_Node **node2);
void			r(t_Node **node);
void			rr(t_Node **node);
int				for_two_numbers(t_Node **node);
int				check_if_sorted(t_Node **node);
int				for_two_numbers(t_Node **node);
void			for_three_numbers(t_Node **node, int max);
int				max_in_list(t_Node **node);
int				check_if_sorted_back(t_Node **node);
int				count_words_split(char const *s, char c);
int				count_words(char **list);
int				check_if_sorted(t_Node **node);
int				min_in_list(t_Node **node);
void			printing_nodes(t_Node *node);
int				check_if_sorted_b(t_Node **node);
void			for_four_numbers(t_Node **node, int counter_el);
int				current_pos(t_Node **node, int arg);
void			algorithm(t_Node **node, int counter_el);
void			printing_nodes(t_Node *node);
void			del(t_Node **node);
int				num_in_ll(t_Node **node);
void			push_first_two(t_Node **node, t_Node **listb);
int				search_for_lower_value(t_Node *node, t_Node **listb);
int				search_for_maks_value(t_Node *node, t_Node **listb);
int				push_cost_b(t_Node *node, t_Node **listb, int c1);
int				push_cost_a(t_Node **lista, t_Node *node, int c2);
t_Node			*node_to_push(t_Node **lista, t_Node **listb);
void			put_the_min(t_Node **node, int counter_el);
void			helper_a(int counter_el, t_Node **node, int target);

#endif
