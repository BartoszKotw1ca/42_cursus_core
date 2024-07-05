#include <iostream>
#include "PhoneBook.class.hpp"

int	main(void)
{
	PhoneBook    sample;
	std::string  chosen;
	
	while (1)
	{
		std::cout << "What do you want to do?" << std::endl;
		std::cout << "Choose a number:" << std::endl;
		std::cout << "1. Add: save a new contact." << std::endl;
		std::cout << "2. Search: display a specific contact." << std::endl;
		std::cout << "3. Exit, contacts are lost forever!!!" << std::endl;
		std::getline(std::cin, chosen);
		if (chosen.length() > 1)
		{
			std::cout << "Invalid option. Try again!" << std::endl;
			continue ;
		}
		switch (chosen[0])
		{
			case '1':
				sample.add();
				break ;
			case '2':
				sample.search();
				break ;
			case '3':
				std::cout << "Thank you for using my book. See you in future!\n";
				return (0);
			default:
				std::cout << "Invalid option. Try again!" << std::endl;
				break ;
		}
	}
}
