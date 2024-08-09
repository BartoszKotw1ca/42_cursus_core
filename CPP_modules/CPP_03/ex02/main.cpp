#include "FragTrap.hpp"

int	main(void)
{
    FragTrap    tmp("Januszek");

    tmp.attack("Krzysiek");
    tmp.attack("Wojtek");
    tmp.beRepaired(10);
    tmp.takeDamage(10);
    tmp.print_e_point();
    tmp.highFivesGuys();
    return (0);
}