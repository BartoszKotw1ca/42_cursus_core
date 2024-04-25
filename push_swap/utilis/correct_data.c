/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:59:57 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/23 11:47:31 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// check if there are another characters than digits and 
// how many - or + there is 
// it should be only one - or one +
int	check_in_char_in_ft_split(char **list, int i, int j, int licznik)
{
	while ((list[i][j] <= '9' && list[i][j] >= '0' && list[i][j])
		|| (list[i][0] == '-' && list[i][j])
		|| (list[i][0] == '+' && list[i][j]))
	{
		if ((list[i][j] == '-' && list[i][j])
		|| (list[i][j] == '+' && list[i][j]))
		{
			licznik ++;
			if (licznik > 1)
				return (0);
		}
		j ++;
	}
	if (list[i][j] != '\0')
		return (0);
	return (1);
}

// this is the continuation of upper function
int	check_if_correct_data_in_ft_split(char **list)
{
	int	i;
	int	j;
	int	licznik;

	i = 0;
	while (list[i])
	{
		j = 0;
		licznik = 0;
		if (check_in_char_in_ft_split(list, i, j, licznik) == 0)
			return (0);
		i ++;
	}
	return (1);
}

// that function only check if every digit appear only one time
int	check_if_every_digit_is_only_one(char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i])
	{
		j = 0;
		while ((ft_atoi(list[i]) != ft_atoi(list[j])) && list[j])
			j ++;
		if ((ft_atoi(list[i]) == ft_atoi(list[j])) && list[j] && j != i)
			return (0);
		i ++;
	}
	return (1);
}

// its checking if the number is out 
// of int
int	check_if_more_less_int(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		if (ft_atoilong(list[i]) > 2147483647
			|| ft_atoilong(list[i]) < -2147483648)
			return (0);
		i ++;
	}
	return (1);
}

// it is just the function connecting all that functions
// if we put " 3 4 2 " 3 4 it will be 0 it is up to me
// bcs the subject does not specife it
int	check_all(char **list)
{
	int	count;

	count = 0;
	while (list[count])
		count ++;
	if (count < 1)
		return (0);
	else if (check_if_correct_data_in_ft_split(list)
		&& check_if_every_digit_is_only_one(list)
		&& check_if_more_less_int(list))
		return (1);
	return (0);
}
