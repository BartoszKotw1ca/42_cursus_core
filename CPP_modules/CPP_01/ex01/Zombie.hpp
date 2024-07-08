#include <iostream>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie 
{
public:
    Zombie( void );
    Zombie ( std::string name );
    ~Zombie ( void );
    void announce ( void );
private:
    std::string _name;
} ;

Zombie* zombieHorde( int N, std::string name );

#endif
