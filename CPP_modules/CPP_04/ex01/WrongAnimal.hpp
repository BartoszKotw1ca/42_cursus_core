#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>


class WrongAnimal
{
    public:
        WrongAnimal( std::string type = "Animal" );
        virtual ~WrongAnimal( void );
        WrongAnimal( const WrongAnimal &other );
        WrongAnimal &operator = ( const WrongAnimal &other );

        void makeSound ( void ) const;
        std::string getType ( void ) const;
    protected:
        std::string _type;
};

#endif