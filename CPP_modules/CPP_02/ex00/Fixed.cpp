#include "Fixed.hpp"

Fixed::Fixed ( void )
{
	f_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( const Fixed& other)
{
	f_point = other.f_point;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator = ( const Fixed& other)
{
	if (this != &other)
		this->setRawBits(other.getRawBits());
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed ( void )
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits ( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->f_point);
}

void	Fixed::setRawBits ( int const raw )
{
	this->f_point = raw;
	std::cout << "setRawBits member function called" << std::endl;
}
