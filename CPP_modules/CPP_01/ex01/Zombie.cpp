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
    // Destructor
}

void Zombie::announce ( void )
{
    std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
