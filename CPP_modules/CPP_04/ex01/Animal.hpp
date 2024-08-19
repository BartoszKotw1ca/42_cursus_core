#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    public:
        Animal( std::string type = "Animal" );
        Animal( const Animal &other );
        Animal &operator = ( const Animal &other );
        virtual ~Animal( void );

        virtual void makeSound ( void ) const;
        std::string getType ( void ) const;
    protected:
        std::string _type;
};

#endif