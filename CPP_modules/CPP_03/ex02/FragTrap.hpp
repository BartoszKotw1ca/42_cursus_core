#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap( std::string name = "No name");
		~FragTrap( void );
		void	highFivesGuys( void );
} ;

#endif