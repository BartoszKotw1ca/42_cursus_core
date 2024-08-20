#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
        Animal( std::string type = "Animal" );
        virtual ~Animal( void );
        Animal( const Animal &other );
        Animal &operator = ( const Animal &other );

        virtual void makeSound( void ) const = 0;
        std::string getType( void ) const;
    protected:
        std::string _type;
};

#endif
