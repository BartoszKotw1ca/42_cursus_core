#ifndef CAT_HPP
#define CAT_HPP

#include "Animals.h"

class Cat : public Animal
{
    public:
        Cat ( void );
        Cat ( const Cat &other );
        Cat &operator = ( const Cat &other );
        ~Cat ( void );
        void makeSound( void ) const;
};

#endif