#include <iostream>
#include "Weapon.hpp"

#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA
{
public:
    Weapon *weapon;

    HumanA ( std::string name, Weapon &weapon);

    void attack( void );
private:
    std::string _name;
};

#endif
