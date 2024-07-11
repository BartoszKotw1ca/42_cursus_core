#include <iostream>
#include "Harl.hpp"

int main( void )
{
    Harl tmp;
    std::cout << "----debug---" << std::endl;
    tmp.complain("DEBUG");
    std::cout << "----info---" << std::endl;
    tmp.complain("INFO");
    std::cout << "----warning---" << std::endl;
    tmp.complain("WARNING");
    std::cout << "----error---" << std::endl;
    tmp.complain("ERROR");
}
