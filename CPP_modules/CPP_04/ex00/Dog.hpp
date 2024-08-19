#ifndef DOG_HPP
#define DOG_HPP

#include "Animals.h"

class Dog : public Animal
{
    public:
        Dog ( void );
        Dog ( const Dog &other );
        Dog &operator = ( const Dog &other );
        ~Dog ( void );
        void makeSound( void ) const;
};

#endif