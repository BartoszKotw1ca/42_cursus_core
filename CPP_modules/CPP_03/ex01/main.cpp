#include "ScavTrap.hpp"

int	main(void)
{
    ScavTrap    tmp("Januszek");
    // ScavTrap    tmp1; // we can uncomment it and try

    tmp.attack("Adam");
    tmp.beRepaired(10);
    tmp.print_e_point();
    // tmp.guardGate();
    return (0);
}
