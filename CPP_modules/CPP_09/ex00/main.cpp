#include "BitcoinExchange.hpp"
// #include "BitcoinExchange.cpp"

int check_arg(int ac)
{
    if (ac != 2)
    {
        std::cerr << "Should be only one argument as a name of a file." << std::endl;
        return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (check_arg(ac))
        return 1;
    (void) av;

    BitcoinExchange tmp1;

    tmp1.save_infile ( av[1] );
    tmp1.save_data ( "data.csv" );
    // tmp1.print_data( 1 );
    // tmp1.print_data( 2 );
    tmp1.print_info();

    return 0;
}
