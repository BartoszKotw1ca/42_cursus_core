#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( void )
{
    this->_name = "NO NAME";
}
Zombie::Zombie( std::string name )
{
    this->_name = name;
}

Zombie::~Zombie( void )
{
    std::cout << "Destructor zombie: " << this->_name << std::endl;
}

void Zombie::announce ( void )
{
    std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
