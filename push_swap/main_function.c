/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:44:49 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/04 08:00:16 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function that is supposed to create a list of numbers
int	*creating_list(int argc, char **argv)
{
	int	j;
	int	i;
	int	*numbers;

	i = 1;
	j = 0;
	numbers = malloc(sizeof(int) * (argc - 1));
	while (i < argc)
		numbers[j ++] = ft_atoi(argv[i ++]);
	return (numbers);
}

// that function should be able to print on stdio numbers in the list
void	printing_numbers(int *numbers, int argc)
{
	int	i;

	i = 0;
	while (numbers[i] && i < argc - 1)
		ft_printf("%d ", numbers[i ++]);
}

int	main(int argc, char **argv)
{
	// sa(numbers);
	// r(numbers, argc);
	int *numbers = creating_list(argc, argv);
	int	*n2;
	n2 = malloc(sizeof(int) * (argc - 1));
	n2[0] = 133;
	printing_numbers(numbers, argc);
	// p(numbers, n2, argc);
	rr(numbers, argc);
	ft_printf("\n");
	printing_numbers(numbers, argc);
}