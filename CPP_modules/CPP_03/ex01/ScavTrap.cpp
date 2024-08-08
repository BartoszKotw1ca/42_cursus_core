#include "ScavTrap.hpp"

ScavTrap::ScavTrap ( const std::string name) : ClapTrap ( name )
{
    std::cout << "Constructor called(ScavTrap)" << std::endl;
    this->_health = 100;
    this->_e_point = 50;
    this->_att_damage = 20;
}

ScavTrap::~ScavTrap ( void )
{
	std::cout << "Destructor called(ScavTrap)" << std::endl;
}

void    ScavTrap::guardGate( void )
{
    std::cout << "ScavTrap " << this->_name
    << " is now in Gate keeper mode!" << std::endl;
}
