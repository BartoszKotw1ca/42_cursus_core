#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animals.h"

class WrongAnimal
{
    public:
        WrongAnimal( std::string type = "Animal" ) : _type (type)
            { std::cout << "Wrong Animal constructor called" << std::endl; };
        virtual ~WrongAnimal( void ){ std::cout << "Wrong Animal destructor called" << std::endl; };
        WrongAnimal( const WrongAnimal &other ) { *this = other; std::cout << "Wrong Animal copy constructor called" << std::endl; };
        WrongAnimal &operator = ( const WrongAnimal &other ) { this->_type = other._type; return *this; std::cout
        << "Wrong Animal copy assignment operator called" << std::endl; };

        void    makeSound ( void ) const { std::cout << "Wrong Animal sound\n"; };
        std::string     getType ( void ) const { return this->_type; };
    protected:
        std::string _type;
} ;

#endif