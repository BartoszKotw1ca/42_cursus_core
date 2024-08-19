#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "Constructor called(FragTrap)" << std::endl;
	this->_health = 100;
	this->_e_point = 100;
	this->_att_damage = 30;
}

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap ( other )
{
    this->_name = other._name;
    this->_health = other._health;
    this->_e_point = other._e_point;
    this->_att_damage = other._att_damage;
    std::cout << "Copy constructor called(FragTrap)" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& other)
{
    if (this == &other)
        return (*this);
    this->_name = other._name;
    this->_health = other._health;
    this->_e_point = other._e_point;
    this->_att_damage = other._att_damage;
    std::cout << "Assignation operator called(FragTrap)" << std::endl;
    return (*this);
}

FragTrap::~FragTrap( void )
{
	std::cout << "Destructor called(FragTrap)" << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->_name << " High five! 🙌" << std::endl;
}
