#include "ClapTrap.hpp"

void    test1()
{
    // Test Constructor and Destructor Messages
    {
        ClapTrap hum1("TestBot");
    } // Destructor should be called here

    ClapTrap hum1("TestBot");

    // Test Energy Points Depletion
    for (int i = 0; i < 11; i++)
        hum1.attack("Adam");
    hum1.print_e_point(); // Should show 0 energy points

    // Test Health Depletion
    for (int i = 0; i < 15; i++)
        hum1.takeDamage(1);
    hum1.print_e_point(); // Should show 0 energy points

    // Test Over-Healing
    hum1.beRepaired(5); // Should not increase health as it's already 0

    // Test No Energy Points for Repair
    hum1.beRepaired(1); // Should print no energy points message

}

void    test2()
{
    ClapTrap	hum1 = ClapTrap();

    for (int i = 0; i < 5; i ++)
        hum1.attack("Adam");

    hum1.print_e_point();

    for (int i = 0; i < 7; i ++)
        hum1.takeDamage(i);

    hum1.print_e_point();

    for (int i = 0; i < 6; i ++)
        hum1.beRepaired(i);

    hum1.print_e_point();
}

int	main(void)
{
    // test1();
    // test2();
    ClapTrap hum1("TestBot");
    ClapTrap hum2(hum1);

    hum2 = hum1;
	return (0);
}

