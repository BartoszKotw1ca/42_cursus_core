#ifndef DOG_HPP
#define DOG_HPP

#include "Animals.h"

class Dog : public Animal
{
    public:
        Dog ( void ) { this->_type = "Dog"; std::cout << "Dog constructor\n"; };
        ~Dog ( void ) { std::cout << "Dog destructor\n"; };
        void    makeSound( void ) const { std::cout << "Dog sound\n"; };
} ;

#endif