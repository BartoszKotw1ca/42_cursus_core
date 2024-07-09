#include <iostream>
#include "Weapon.hpp"

#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB
{
public:
    Weapon *weapon;

    HumanB ( std::string name);

    void attack( void );
    void setWeapon( Weapon &weapon);
private:
    std::string _name;
};

#endif
