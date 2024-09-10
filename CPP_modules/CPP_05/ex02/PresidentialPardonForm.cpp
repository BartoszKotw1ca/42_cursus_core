#include "PresidentialPardonForm.hpp"

PresidentialPardonForm :: PresidentialPardonForm ( std::string target) : AForm( "PresidentialPardonForm", 25, 5 )
{
    std::cout << BLUE << "Presidential Pardon Form constructor !" << OR << std::endl;
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm :: ~PresidentialPardonForm ( void )
{
    std::cout << "Presidential Pardon Form destructor !" << std::endl;
}

void PresidentialPardonForm :: executee ( void ) const
{
    std::cout << "Im the Presidential Pardon Form !!!" << std::endl;
}
