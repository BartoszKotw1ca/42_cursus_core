#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

class ScalarConverter
{
    public:
        ScalarConverter ( void );
        ~ScalarConverter ( void );
        // ScalarConverter & operator=( const ScalarConverter &other);
        // ScalarConverter( const ScalarConverter &other);
        static convert( std::string literal);
} ;

#endif
