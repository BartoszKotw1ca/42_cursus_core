#include "Cat.hpp"
#include <iostream>

Cat::Cat ( void ) : _brain ( new Brain() )
{
    this->_type = "Cat";
    std::cout << "Cat constructor\n";
}

Cat::Cat ( const Cat &other ) : Animal(other)
{
    _brain = new Brain(*other._brain);
    std::cout << "Cat copy constructor\n";
}

Cat &Cat::operator = ( const Cat &other )
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << "Cat copy assignment operator\n";
    return *this;
}

Cat::~Cat ( void )
{
    delete _brain;
    std::cout << "Cat destructor\n";
}

void Cat::makeSound( void ) const
{
    std::cout << "Cat sound\n";
}