#include <iostream>
#include "Zombie.hpp"

int main( void )
{
    Zombie *tmp;

    tmp = newZombie("Januszek");
    tmp->announce();
    randomChump("Januszek");
    delete tmp;
    return 0;
}
