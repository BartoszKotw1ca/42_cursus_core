#ifndef CAT_HPP
#define CAT_HPP

#include "Animals.h"

class Cat : public Animal
{
    public:
        Cat ( void ) { this->_type = "Cat"; std::cout << "Cat constructor\n"; };
        ~Cat ( void ) { std::cout << "Cat destructor\n"; };
        void    makeSound( void ) const { std::cout << "Cat sound\n"; };
} ;

#endif