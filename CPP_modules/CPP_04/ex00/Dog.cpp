#include "Dog.hpp"

Dog::Dog ( void )
{
    this->_type = "Dog";
    std::cout << "Dog constructor\n";
}

Dog::Dog ( const Dog &other ) : Animal(other)
{
    *this = other;
    std::cout << "Dog copy constructor\n";
}

Dog &Dog::operator = ( const Dog &other )
{
    if (this != &other)
    {
        Animal::operator=(other);
        this->_type = other._type;
    }
    std::cout << "Dog copy assignment operator\n";
    return *this;
}

Dog::~Dog ( void )
{
    std::cout << "Dog destructor\n";
}

void Dog::makeSound( void ) const
{
    std::cout << "Dog sound\n";
}