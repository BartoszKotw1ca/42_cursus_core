#include "ScalarConverter.hpp"

ScalarConverter :: ScalarConverter ( void )
{
    std::cout << "ScalarConverter constructor." << std::endl;
}

ScalarConverter :: ~ScalarConverter ( void )
{
    std::cout << "ScalarConverter destructor." << std::endl;
}

ScalarConverter & ScalarConverter :: operator = ( const ScalarConverter & other)
{
    (void) other;
    return *this;
}

ScalarConverter :: ScalarConverter ( const ScalarConverter & other)
{
    (void) other;
    *this = other;
}

void ScalarConverter :: convert ( std::string literal )
{
    std::cout << std::fixed << std::setprecision(2);
    if (std::isnan(std::atof(literal.c_str())) == 1
        || std::isinf(std::atof(literal.c_str())) == 1)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << std::atoi(literal.c_str()) << std::endl;
    if (std::atoi(literal.c_str()) <= 126 && std::atoi(literal.c_str()) >= 32)
        std::cout << "char: " << static_cast<char>(std::atoi(literal.c_str())) << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    std::cout << "float: " << static_cast<float>(std::atof(literal.c_str())) << "f" << std::endl;
    std::cout << "double: " << (std::atof(literal.c_str())) << std::endl;
}
