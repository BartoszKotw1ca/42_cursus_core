#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap ( const std::string name = "No name");
        ~ScavTrap ( void );
        void    guardGate( void );
} ;

#endif
