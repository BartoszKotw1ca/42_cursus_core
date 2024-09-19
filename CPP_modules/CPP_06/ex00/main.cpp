#include "ScalarConverter.hpp"

void test_for_int()
{
    ScalarConverter::convert( "0" );
    std::cout << "      -----------" << std::endl;
    ScalarConverter::convert( "42" );
    std::cout << "      -----------" << std::endl;
    ScalarConverter::convert( "-42" );
    std::cout << "      -----------" << std::endl;
}

void test_for_char()
{
    ScalarConverter::convert( "c" );
    std::cout << "      -----------" << std::endl;
    ScalarConverter::convert( "x" );
    std::cout << "      -----------" << std::endl;
}

void test_for_double()
{
    ScalarConverter::convert( "0.0" );
    std::cout << "      -----------" << std::endl;
    ScalarConverter::convert( "4.2" );
    std::cout << "      -----------" << std::endl;
    ScalarConverter::convert( "-4.2" );
    std::cout << "      -----------" << std::endl;
}

void test_for_float()
{
    ScalarConverter::convert( "0.0f" );
    std::cout << "      -----------" << std::endl;
    ScalarConverter::convert( "-4.2f" );
    std::cout << "      -----------" << std::endl;
    ScalarConverter::convert( "4.2f" );
    std::cout << "      -----------" << std::endl;
}

void my_test()
{
    std::cout << "      -----------" << std::endl;
    ScalarConverter::convert( "28.123456789123456789f" );
    std::cout << "      -----------" << std::endl;
    ScalarConverter::convert( "28.12345" );
    std::cout << "      -----------" << std::endl;
    ScalarConverter::convert( "c" );
    std::cout << "      -----------" << std::endl;
    ScalarConverter::convert( "x" );
    std::cout << "      -----------" << std::endl;
    ScalarConverter::convert( "nan" );
    std::cout << "      -----------" << std::endl;
    ScalarConverter::convert( "nanf" );
    std::cout << "      -----------" << std::endl;
    ScalarConverter::convert( "+inf" );
    std::cout << "      -----------" << std::endl;
    ScalarConverter::convert( "-inf" );
    std::cout << "      -----------" << std::endl;
    ScalarConverter::convert( "+inff" );
    std::cout << "      -----------" << std::endl;
    ScalarConverter::convert( "-inff" );
    std::cout << "      -----------" << std::endl;
}

int main(int ac, char **av)
{
    (void) ac;
    (void) av;
    ScalarConverter::convert(av[1]);

    // my_test();
    // test_for_int();
    // test_for_float();
    // test_for_double()
    // test_for_char();
}
