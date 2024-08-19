#include "Cat.hpp"

Cat::Cat ( void )
{
    this->_type = "Cat";
    std::cout << "Cat constructor\n";
}

Cat::Cat ( const Cat &other ) : Animal(other)
{
    *this = other;
    std::cout << "Cat copy constructor\n";
}

Cat &Cat::operator = ( const Cat &other )
{
    if (this != &other)
    {
        Animal::operator=(other);
        this->_type = other._type;
    }
    std::cout << "Cat copy assignment operator\n";
    return *this;
}

Cat::~Cat ( void )
{
    std::cout << "Cat destructor\n";
}

void Cat::makeSound( void ) const
{
    std::cout << "Cat sound\n";
}