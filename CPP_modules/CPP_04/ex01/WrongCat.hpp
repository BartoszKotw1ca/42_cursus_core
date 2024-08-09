#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "Animals.h"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat ( void ) { this->_type = "Wrong Cat"; std::cout << " Wrong Cat constructor\n"; };
        ~WrongCat ( void ) { std::cout << "Wrong Cat destructor\n"; };
        void    makeSound( void ) const { std::cout << "Wrong Cat sound\n"; };
} ;

#endif