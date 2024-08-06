#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
public:
	Fixed ( void );
	Fixed ( const int f_point);
	Fixed ( const float f_point);
	Fixed ( const Fixed& other );
	Fixed& operator = ( const Fixed& other );
	~Fixed ( void );
	int		getRawBits ( void ) const;
	void	setRawBits( int const raw);
	float	toFloat ( void ) const;
	int		toInt ( void ) const;
	friend	std::ostream& operator << (std::ostream& out, const Fixed& fixed);
private:
	int					_f_point;
	static const int	_f_bits = 8;
} ;

#endif
