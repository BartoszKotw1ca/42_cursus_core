#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name (name)
{
	_health = 10;
	_e_point = 10;
	_att_damage = 0;
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap ( void )
{
	std::cout << "Destructor called" << std::endl;
}

void    ClapTrap::print_no_points( void )
{
    std::cout << "ClatTrap " << this->_name << " has \
no energy points!" << std::endl;
}

void    ClapTrap::attack ( const std::string& target)
{
    if (this->_e_point > 0 && this->_health > 0)
    {
        this->_e_point --;
        std::cout << "ClapTrap " << this->_name << " attacks "
        << target << ", causing " << this->_att_damage
        << " points of damage!" << std::endl;
    }
    else
        print_no_points();
}

void    ClapTrap::takeDamage ( unsigned int amount )
{
    if (this->_health > 0)
    {
        this->_health -= amount;
        if (this->_health <= 0)
            std::cout << "ClapTrap " << this->_name
            << " died" << std::endl;
        else
            std::cout << "ClapTrap " << this->_name
            << " took damage " << amount
            << " now has " << this->_health << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->_name
        << " is already destroyed!" << std::endl;
}

void    ClapTrap::beRepaired ( unsigned int amount )
{
    if (this->_e_point > 0)
    {
        if (this->_health < 10 && this->_health + amount <= 10)
        {
            this->_health += amount;
            this->_e_point --;
            std::cout << "ClapTrap " << this->_name
            << " had (HP) " << this->_health - amount
            << " now has " << this->_health << std::endl;
        }
        else
            std::cout << "ClapTrap " << this->_name
            << " has too much HP " << std::endl;
    }
    else
        print_no_points();
}

void    ClapTrap::print_e_point(void)
{
    std::cout << "Energy points: " << this->_e_point << std::endl;
}
