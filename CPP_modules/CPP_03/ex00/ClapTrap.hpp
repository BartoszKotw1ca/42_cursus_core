#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap ( void );
		ClapTrap ( std::string name );
		~ClapTrap ( void );
		void	attack ( const std::string& target );
		void	takeDamage ( unsigned int amount );
		void	beRepaired ( unsigned int amount );
	private:
		std::string	_name;
		int			_health;
		int			_n_point;
		int			_att_damage;
} ;

#endif
