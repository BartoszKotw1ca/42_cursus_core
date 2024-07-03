/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:05:32 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/03 14:57:15 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

int	main(int ac, char **av)
{
	if (ac == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE ";
	for (int i = 1; av[i]; i ++)
		for (int j = 0; av[i][j]; j ++)
			cout << (char)toupper(av[i][j]);
	cout << '\n';
	return (0);
}
