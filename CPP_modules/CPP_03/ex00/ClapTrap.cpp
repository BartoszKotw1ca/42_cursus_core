#include "ClapTrap.hpp"

ClapTrap::ClapTrap ( void )
{
	_name = "No name";
	_health = 10;
	_n_point = 10;
	_att_damage = 0;
}

ClapTrap::ClapTrap( std::string name ) : _name (name)
{
	_health = 10;
	_n_point = 10;
	_att_damage = 0;
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap ( void )
{
	std::cout << "Destructor called" << std::endl;
}
