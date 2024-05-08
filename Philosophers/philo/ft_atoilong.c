/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoilong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:29:21 by bkotwica          #+#    #+#             */
/*   Updated: 2024/05/03 14:37:06 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// i need it to check if number is bigger
// or lower than int, bcs it musnt
long long int	ft_atoilong(const char *nptr)
{
	char			*nr;
	long long		i;
	long long		sign;
	long long		num;

	num = 0;
	sign = 1;
	i = 0;
	nr = (char *) nptr;
	if (nr[i] == '-' || nr[i] == '+')
	{
		if (nr[i] == '-')
			sign = -1;
		i ++;
	}
	if (nr[i] == '0')
		return (-1);
	while (nr[i])
	{
		if (!(nr[i] <= '9' && nr[i] >= '0'))
			return (-1);
		num = num * 10 + nr[i] - '0';
		i ++;
	}
	return (sign * num);
}
