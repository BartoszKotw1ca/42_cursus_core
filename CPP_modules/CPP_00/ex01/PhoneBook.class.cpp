#include <iostream>
#include "PhoneBook.class.hpp"
#include <iomanip>

PhoneBook::PhoneBook( void )
{
	this->num_of_con = 0;
	std::cout << "Class builded" << std::endl;
}

PhoneBook::~PhoneBook( void )
{
	std::cout << "Class destroyd" << std::endl;
}

void	PhoneBook::add( void )
{
	if (this->num_of_con >= 8)
	{
		this->num_of_con = 7;
		std::cout << "The book is full, i have to delete last record!\n";
	}
	std::cout << "First name: ";
	std::getline(std::cin, this->first_name[this->num_of_con]);
	std::cout << "Last name: ";
	std::getline(std::cin, this->last_name[this->num_of_con]);
	std::cout << "Nickname: ";
	std::getline(std::cin, this->nickname[this->num_of_con]);
	std::cout << "Phone number: ";
	std::getline(std::cin, this->phone_num[this->num_of_con]);
	std::cout << "Your darkest secret: ";
	std::getline(std::cin, this->secret[this->num_of_con]);
	this->num_of_con += 1;
}

void	PhoneBook::print_info(int i)
{
	std::cout << "First name:   " << this->first_name[i] << std::endl;
	std::cout << "Last name:    " << this->last_name[i] << std::endl;
	std::cout << "Nickname:     " << this->nickname[i] << std::endl;
	std::cout << "Phone number: " << this->phone_num[i] << std::endl;
	std::cout << "Secret:       "<< this->secret[i] << std::endl;
}

void	PhoneBook::search( void )
{
	std::string    index;
	if (this->num_of_con == 0)
		std::cout << "Phone book is empty!" << std::endl;
	for (int i = 0; i < this->num_of_con; i ++)
	{
		std::string firstname = this->first_name[i].substr(0, 9);
		std::string lastname = this->last_name[i].substr(0, 9);
		std::string nick = this->nickname[i].substr(0, 9);
		if (this->first_name[i].length() >= 10)
			firstname += '.';
		if (this->last_name[i].length() >= 10)
			lastname += '.';
		if (this->nickname[i].length() >= 10)
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
