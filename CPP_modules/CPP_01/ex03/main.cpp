#include <iostream>
// #include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

// int main( void )
// {
//     Weapon tmp;
//     std::cout << tmp.getType() << std::endl;
//     tmp.setType("AMG");
//     std::cout << tmp.getType() << std::endl;
//     HumanA human("Bob", tmp);
//     human.attack();
//     std::cout << human.weapon.getType() << std::endl;
//     human.weapon.setType("STS");
//     std::cout << human.weapon.getType() << std::endl;
//     human.attack();
// }
int main ( void )
{
    {
        Weapon club = Weapon ( "crude spiked club" );

        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon ( "crude spiked club" );

        HumanB jim( "Jim" );
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
}
