#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Animals.h"

class Animal
{
    public:
        Animal( std::string type = "Animal" ) : _type (type)
            { std::cout << "Animal constructor called" << std::endl; };
        virtual ~Animal( void ){ std::cout << "Animal destructor called" << std::endl; };
        Animal( const Animal &other ) { *this = other; std::cout << "Animal copy constructor called" << std::endl; };
        Animal &operator = ( const Animal &other ) { this->_type = other._type; return *this; std::cout
        << "Animal copy assignment operator called" << std::endl; };

        virtual void    makeSound ( void ) const = 0;
        std::string     getType ( void ) const { return this->_type; };
    protected:
        std::string _type;
} ;

#endif