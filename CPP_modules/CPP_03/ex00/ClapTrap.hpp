#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    public:
        ClapTrap ( std::string name = "No name");
        ~ClapTrap ( void );
        void    attack ( const std::string& target );
        void    takeDamage ( unsigned int amount );
        void    beRepaired ( unsigned int amount );
        void    print_e_point( void );
    private:
        std::string	_name;
        int _health;
        int _e_point;
        int _att_damage;
        void    print_no_points( void );
} ;

#endif
