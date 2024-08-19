#include "WrongCat.hpp"

WrongCat::WrongCat ( void )
{
    this->_type = "Wrong Cat";
    std::cout << "Wrong Cat constructor\n";
}

WrongCat::WrongCat ( const WrongCat &other ) : WrongAnimal(other)
{
    *this = other;
    std::cout << "Wrong Cat copy constructor\n";
}

WrongCat &WrongCat::operator = ( const WrongCat &other )
{
    if (this != &other)
    {
        WrongAnimal::operator=(other);
        this->_type = other._type;
    }
    std::cout << "Wrong Cat copy assignment operator\n";
    return *this;
}

WrongCat::~WrongCat ( void )
{
    std::cout << "Wrong Cat destructor\n";
}

void WrongCat::makeSound( void ) const
{
    std::cout << "Wrong Cat sound\n";
}