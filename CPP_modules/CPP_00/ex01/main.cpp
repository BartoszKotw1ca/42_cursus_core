#include <iostream>
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook    sample;
	std::string  chosen;
	
	while (1)
	{
		std::cout << "What do you want to do?" << std::endl;
		std::cout << "1. ADD: save a new contact." << std::endl;
		std::cout << "2. SEARCH: display a specific contact." << std::endl;
		std::cout << "3. EXIT, contacts are lost forever!!!" << std::endl;
		std::getline(std::cin, chosen);
        if (chosen == "ADD" && chosen.length() == 3)
            sample.add();
        else if (chosen == "SEARCH" && chosen.length() == 6)
            sample.search();
        else if (chosen == "EXIT" && chosen.length() == 4)
        {
            std::cout << "Thank you for using my book. See you in future!\n";
            return (0);
        }
		else
		{
			std::cout << "Invalid option. Try again!" << std::endl;
			continue ;
		}
	}
}
