#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( std::string type ) : _type(type)
{
    std::cout << "Wrong Animal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &other )
{
    *this = other;
    std::cout << "Wrong Animal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator = ( const WrongAnimal &other )
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    std::cout << "Wrong Animal copy assignment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "Wrong Animal destructor called" << std::endl;
}

void WrongAnimal::makeSound ( void ) const
{
    std::cout << "Wrong Animal sound\n";
}

std::string WrongAnimal::getType ( void ) const
{
    return this->_type;
}