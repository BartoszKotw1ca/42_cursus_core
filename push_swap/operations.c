/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:29:25 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/04 08:04:10 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function to swap a or b, a and b
void	s(int *s1)
{
	int	tmp;
	tmp = s1[1];
	s1[1] = s1[0];
	s1[0] = tmp;
}

// function to push first element to the top of s1
void	p(int *s1, int *s2,int i)
{
	while (i-- != 0)
		s1[i] = s1[i - 1];
	s1[0] = s2[0];
}

// function to Shift up all elemnts first become last one
void	r(int *s1, int argc)
{
	int	i;
	int	tmp;

	tmp = s1[0];
	i = 0;
	while (i < argc - 1)
	{
		s1[i] = s1[i + 1];
		i ++;
	}
	s1[i - 1] = tmp;
}

// function to Shift down all elements last goes first
void	rr(int *s1, int i)
{
	int	tmp;

	tmp = s1[i - 2];
	while (i-- != 0)
		s1[i] = s1[i - 1];
	s1[0] = tmp;
}