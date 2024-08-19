#include "Animal.hpp"

Animal::Animal( std::string type ) : _type(type)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal( void )
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal( const Animal &other )
{
    *this = other;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator = ( const Animal &other )
{
    this->_type = other._type;
    std::cout << "Animal copy assignment operator called" << std::endl;
    return *this;
}

void Animal::makeSound ( void ) const
{
    std::cout << "Animal sound\n";
}

std::string Animal::getType ( void ) const
{
    return this->_type;
}