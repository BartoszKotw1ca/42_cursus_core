#include "Fixed.hpp"

Fixed::Fixed ( void )
{
	this->_f_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( const int f_point) : _f_point ( f_point << Fixed::_f_bits )
{
	std::cout << "Default INT constructor called" << std::endl;
}

// 1 << 8 jest to rownoznaczne z 2 ^ 8
// jest ona mnozona razy tyle aby zamienic
// ja na staloprzecinkowa
Fixed::Fixed ( const float f_point ) : _f_point ( roundf(f_point * (1 << Fixed::_f_bits)) )
{
	std::cout << "Defalut FLOAT constructor called" << std::endl;
}

Fixed::Fixed ( const Fixed& other)
{
	_f_point = other._f_point;
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
	return (this->_f_point);
}

void	Fixed::setRawBits ( int const raw )
{
	this->_f_point = raw;
}

float	Fixed::toFloat ( void ) const
{
	return float(this->_f_point) / (1 << Fixed::_f_bits);
}

int	Fixed::toInt ( void ) const
{
	return this->_f_point >> Fixed::_f_bits;
}

// that allows me to print on the std::cout the value
std::ostream& operator << (std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
