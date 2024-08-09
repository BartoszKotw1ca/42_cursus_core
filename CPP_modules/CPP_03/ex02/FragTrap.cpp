#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "Constructor called(FragTrap)" << std::endl;
	this->_health = 100;
	this->_e_point = 100;
	this->_att_damage = 30;
}

FragTrap::~FragTrap( void )
{
	std::cout << "Destructor called(FragTrap)" << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->_name << " High five! 🙌" << std::endl;
}
