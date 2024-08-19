#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    public:
        ClapTrap ( std::string name = "No name");
        ~ClapTrap ( void );
        ClapTrap ( const ClapTrap& other);
        ClatTrap& operator = (const ClapTrap& other);
        void    attack ( const std::string& target );
        void    takeDamage ( unsigned int amount );
        void    beRepaired ( unsigned int amount );
        void    print_e_point( void );
    protected:
        std::string	_name;
        int _health;
        int _e_point;
        int _att_damage;
        void    print_no_points( void );
} ;

#endif
