/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:44:37 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/22 12:29:38 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_arg(int argc, char **argv, char ***list, int *counter_words)
{
	if (argc == 1)
		exit (0);
	if (argc == 2)
	{
		*counter_words = count_words_split(argv[1], ' ');
		*list = ft_split(argv[1], ' ');
	}
	if (argc > 2)
	{
		*counter_words = count_words(argv + 1);
		*list = argv + 1;
	}
	if (*counter_words == 1)
		exit(1);
	if (!check_all(*list))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	process_list(t_Node **lista, int counter_words)
{
	if (counter_words == 2)
		for_two_numbers(lista);
	else if (counter_words == 3)
		for_three_numbers(lista, max_in_list(lista));
	else if (counter_words == 4)
		for_four_numbers(lista, counter_words);
	else if (counter_words >= 5)
		algorithm(lista, counter_words);
	del(lista);
}

int	main(int argc, char **argv)
{
	char	**list;
	t_Node	*lista;
	int		counter_words;

	list = NULL;
	counter_words = 0;
	parse_arg(argc, argv, &list, &counter_words);
	lista = create_node_list(list);
	if (check_if_sorted(&lista))
		exit (1);
	process_list(&lista, counter_words);
	return (0);
}
