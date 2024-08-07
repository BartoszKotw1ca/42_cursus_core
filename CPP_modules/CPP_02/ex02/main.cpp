#include "Fixed.hpp"

void	first_part(const Fixed *a, const Fixed *b, 
	const Fixed *c, const Fixed *d)
{
	std::cout << "First part:" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "b < c: " << (b < c) << std::endl;
	std::cout << "c < d: " << (c < d) << std::endl;
	std::cout << "d < a: " << (d < a) << std::endl;

	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "b > c: " << (b > c) << std::endl;
	std::cout << "c > d: " << (c > d) << std::endl;
	std::cout << "d > a: " << (d > a) << std::endl;

	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "b <= c: " << (b <= c) << std::endl;
	std::cout << "c <= d: " << (c <= d) << std::endl;
	std::cout << "b <= d: " << (b <= d) << std::endl;

	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "b >= c: " << (b >= c) << std::endl;
	std::cout << "c >= d: " << (c >= d) << std::endl;
	std::cout << "b >= d: " << (b >= d) << std::endl;

	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "b == c: " << (b == c) << std::endl;
	std::cout << "c == d: " << (c == d) << std::endl;
	std::cout << "b == d: " << (b == d) << std::endl;

	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << "b != c: " << (b != c) << std::endl;
	std::cout << "c != d: " << (c != d) << std::endl;
	std::cout << "b != d: " << (b != d) << std::endl;
}


void	second_part(const Fixed *a, const Fixed *b, 
	const Fixed *c, const Fixed *d)
{
	std::cout << "Second part:" << std::endl;
	std::cout << "a + b: " << (*a + *b) << std::endl;
	std::cout << "b + c: " << (*b + *c) << std::endl;
	std::cout << "c + d: " << (*c + *d) << std::endl;
	std::cout << "b + d: " << (*b + *d) << std::endl;

	std::cout << "a - b: " << (*a - *b) << std::endl;
	std::cout << "b - c: " << (*b - *c) << std::endl;
	std::cout << "c - d: " << (*c - *d) << std::endl;
	std::cout << "b - d: " << (*b - *d) << std::endl;

	std::cout << "a * b: " << (*a * *b) << std::endl;
	std::cout << "b * c: " << (*b * *c) << std::endl;
	std::cout << "c * d: " << (*c * *d) << std::endl;
	std::cout << "b * d: " << (*b * *d) << std::endl;

	std::cout << "a / b: " << (*a / *b) << std::endl;
	std::cout << "b / c: " << (*b / *c) << std::endl;
	std::cout << "c / d: " << (*c / *d) << std::endl;
	std::cout << "b / d: " << (*b / *d) << std::endl;
}

void	third_part(Fixed a)
{
	std::cout << "Third part:" << std::endl;
	std::cout << a++ << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
}

void	to_int(Fixed a, Fixed b, Fixed c, Fixed d)
{
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

}

int	main( void )
{
	Fixed		a;
	Fixed const	b( 10 );
	Fixed const	c( 42.42f );
	Fixed const	d( b );

	a = Fixed ( 1234.4321f );

	// to_int(a, b, c, d);
	// first_part(&a, &b, &c, &d);
	// second_part(&a, &b, &c, &d);
	// third_part(a);

	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	return (0);
}
