#include "Dog.hpp"

Dog::Dog( void ) : _brain( new Brain() )
{
    this->_type = "Dog";
    std::cout << "Dog constructor\n";
}

Dog::~Dog( void )
{
    delete _brain;
    std::cout << "Dog destructor\n";
}

void Dog::makeSound( void ) const
{
    std::cout << "Dog sound\n";
}
