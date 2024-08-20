#include "Cat.hpp"

Cat::Cat( void ) : _brain( new Brain() )
{
    this->_type = "Cat";
    std::cout << "Cat constructor\n";
}

Cat::~Cat( void )
{
    delete _brain;
    std::cout << "Cat destructor\n";
}

void Cat::makeSound( void ) const
{
    std::cout << "Cat sound\n";
}
