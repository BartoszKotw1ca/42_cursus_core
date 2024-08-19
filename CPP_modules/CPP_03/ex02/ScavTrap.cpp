#include "ScavTrap.hpp"

ScavTrap::ScavTrap ( const std::string name) : ClapTrap ( name )
{
    std::cout << "Constructor called(ScavTrap)" << std::endl;
    this->_health = 100;
    this->_e_point = 50;
    this->_att_damage = 20;
}

ScavTrap::ScavTrap ( const ScavTrap& other ) : ClapTrap ( other )
{
    this->_name = other._name;
    this->_health = other._health;
    this->_e_point = other._e_point;
    this->_att_damage = other._att_damage;
    std::cout << "Copy constructor called(ScavTrap)" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& other)
{
    if (this == &other)
        return (*this);
    this->_name = other._name;
    this->_health = other._health;
    this->_e_point = other._e_point;
    this->_att_damage = other._att_damage;
    std::cout << "Assignation operator called(ScavTrap)" << std::endl;
    return (*this);
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
