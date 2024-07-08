#include <iostream>
#include "Zombie.hpp"

int main( void )
{
    int num = 10; // We can change that to the number we want
    Zombie *horde = zombieHorde(num, "Januszek");
    for (int i = 0; i < num; i ++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}
