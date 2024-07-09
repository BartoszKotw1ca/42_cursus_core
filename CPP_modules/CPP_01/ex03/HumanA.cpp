#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA ( std::string name, Weapon &weapon) : weapon ( &weapon ), _name( name )
{
    return ;
}

void HumanA::attack ( void )
{
    std::cout << this->_name << " attacks with their "
        << weapon->getType() << std::endl;
}
