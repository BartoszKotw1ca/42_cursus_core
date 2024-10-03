#include "RPN.hpp"

int main(int ac, char **av)
{
    RPN tmp1;

    if (tmp1.check_input(av[1], ac))
        return (0);
    tmp1.algorithm();
    return (0);
}
