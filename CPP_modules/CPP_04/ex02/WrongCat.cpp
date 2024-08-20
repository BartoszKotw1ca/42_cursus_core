#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
    this->_type = "Wrong Cat";
    std::cout << "Wrong Cat constructor\n";
}

WrongCat::~WrongCat( void )
{
    std::cout << "Wrong Cat destructor\n";
}

void WrongCat::makeSound( void ) const
{
    std::cout << "Wrong Cat sound\n";
}
