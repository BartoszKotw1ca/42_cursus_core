#include <iostream>
#include "PhoneBook.hpp"
#include <iomanip>

std::string& Contact::tmp( void )
{
    return this->_tmp;
}

std::string& Contact::first_name( void )
{
    return this->_first_name;
}

std::string& Contact::last_name( void )
{
    return this->_last_name;
}

std::string& Contact::nickname( void )
{
    return this->_nickname;
}

std::string& Contact::phone_num( void )
{
    return this->_phone_num;
}

std::string& Contact::secret( void )
{
    return this->_secret;
}

PhoneBook::PhoneBook( void )
{
	this->num_of_con = 0;
}

PhoneBook::~PhoneBook( void )
{
	std::cout << "Bye!" << std::endl;
}

void	PhoneBook::add( void )
{
	if (this->num_of_con >= 8)
	{
		std::cout << "The book is full, i have to delete oldest record!\n";
        this->contacts[this->num_of_con % 8].first_name() = "";
        this->contacts[this->num_of_con % 8].last_name() = "";
        this->contacts[this->num_of_con % 8].nickname() = "";
        this->contacts[this->num_of_con % 8].phone_num() = "";
        this->contacts[this->num_of_con % 8].secret() = "";
	}
	while (this->contacts[this->num_of_con % 8].first_name() == ""
        || this->contacts[this->num_of_con % 8].last_name() == ""
        || this->contacts[this->num_of_con % 8].nickname() == ""
        || this->contacts[this->num_of_con % 8].phone_num() == ""
        || this->contacts[this->num_of_con % 8].secret() == "")
    {
        std::cout << "Any field should not be empty" << std::endl;
        std::cout << "First name: ";
        std::getline(std::cin, this->contacts[this->num_of_con % 8].first_name());
        std::cout << "Last name: ";
        std::getline(std::cin, this->contacts[this->num_of_con % 8].last_name());
        std::cout << "Nickname: ";
        std::getline(std::cin, this->contacts[this->num_of_con % 8].nickname());
        std::cout << "Phone number: ";
        std::getline(std::cin, this->contacts[this->num_of_con % 8].phone_num());
        std::cout << "Your darkest secret: ";
        std::getline(std::cin, this->contacts[this->num_of_con % 8].secret());
        std::cout << "" << std::endl;
    }
    this->num_of_con += 1;
}

void	PhoneBook::print_info(int i)
{
	std::cout << "First name:   " << this->contacts[i].first_name() << std::endl;
	std::cout << "Last name:    " << this->contacts[i].last_name() << std::endl;
	std::cout << "Nickname:     " << this->contacts[i].nickname() << std::endl;
	std::cout << "Phone number: " << this->contacts[i].phone_num() << std::endl;
	std::cout << "Secret:       "<< this->contacts[i].secret() << std::endl;
}

void	PhoneBook::search( void )
{
	std::string    index;
	if (this->num_of_con == 0)
	{
        std::cout << "Phone book is empty!" << std::endl;
        return ;
    }
	for (int i = 0; i < (this->num_of_con > 8 ? 8 : this->num_of_con); i ++)
	{
		std::string firstname = this->contacts[i].first_name().substr(0, 9);
		std::string lastname = this->contacts[i].last_name().substr(0, 9);
		std::string nick = this->contacts[i].nickname().substr(0, 9);
		if (this->contacts[i].first_name().length() >= 10)
			firstname += '.';
		if (this->contacts[i].last_name().length() >= 10)
			lastname += '.';
		if (this->contacts[i].nickname().length() >= 10)
			nick += '.';
		std::cout << std::setw(10) << i + 1 << " | " 
			<< std::setw(10)<< firstname << " | " 
			<< std::setw(10) << lastname << " | "  
			<< std::setw(10)<< nick << " | " << std::endl;
	}
	do
	{
		std::cout << "Enter a index which you want to see: ";
		std::getline(std::cin, index);
	}
	while (index.length() > 1 || (int)index[0] - 48 > this->num_of_con 
		|| (int)index[0] - 48 <= 0 || index.empty() != 0);
	this->print_info((int)index[0] - 49);
}
