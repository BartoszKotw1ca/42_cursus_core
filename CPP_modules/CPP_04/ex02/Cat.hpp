#ifndef CAT_HPP
#define CAT_HPP

#include "Animals.h"

class Cat : public Animal
{
    public:
        Cat ( void ) : _brain ( new Brain ()){ this->_type = "Cat"; std::cout << "Cat constructor\n"; };
        ~Cat ( void ) { delete _brain; std::cout << "Cat destructor\n"; };
        void    makeSound( void ) const { std::cout << "Cat sound\n"; };
    private:
        Brain   *_brain;
} ;

#endif