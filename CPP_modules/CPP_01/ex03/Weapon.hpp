#include <iostream>

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon
{
public:
    Weapon( void );
    Weapon ( std::string type);
    ~Weapon ( void );
    const std::string getType ( void );
    void setType( const std::string type);

private:
    std::string _type;
} ;

#endif
