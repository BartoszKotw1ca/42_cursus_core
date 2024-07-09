#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon ( void )
{
    this->_type = "NoThInG";
}

Weapon::~Weapon ( void )
{
    return ;
}

Weapon::Weapon ( std::string type)
{
    this->_type = type;
}

const std::string Weapon::getType ( void )
{
    return (this->_type);
}

void Weapon::setType ( const std::string type)
{
    this->_type = type;
}
