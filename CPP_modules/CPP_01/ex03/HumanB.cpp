#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB ( std::string name) : _name( name)
{
    return ;
}

void HumanB::attack ( void )
{
    std::cout << this->_name << " attacks with their "
        << weapon->getType() << std::endl;
}

void HumanB::setWeapon ( Weapon &weapon)
{
    this->weapon = &weapon;
}
