#include <iostream>
#include <cstdio>
#include <cctype>

// using namespace std;
// We cant use it but after that:
// insted of that std::cout << cos 
// we can cout << cos
int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE ";
	for (int i = 1; av[i]; i ++)
		for (int j = 0; av[i][j]; j ++)
			std::cout << (char)toupper(av[i][j]);
	std::cout << '\n';
	return (0);
}
