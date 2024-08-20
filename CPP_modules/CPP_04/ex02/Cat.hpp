#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat( void );
        ~Cat( void );
        void makeSound( void ) const;
    private:
        Brain *_brain;
};

#endif
