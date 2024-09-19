#pragma once
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>

class ScalarConverter
{
    public:
        ~ScalarConverter ( void );
        ScalarConverter & operator=( const ScalarConverter &other);
        ScalarConverter( const ScalarConverter &other);
        static void convert( std::string literal);
    private:
        ScalarConverter ( void );
} ;

