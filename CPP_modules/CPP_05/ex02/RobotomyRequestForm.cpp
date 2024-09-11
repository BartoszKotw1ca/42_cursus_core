#include "RobotomyRequestForm.hpp"

RobotomyRequestForm :: RobotomyRequestForm ( std::string target) : AForm ( "name", 72, 45 )
{
    std::cout << "RobotomyRequestForm constructor!" << std::endl;
    std::cout << GREEN << "Wrrr, Brrrrr, Wrrrrrr !!!" << OR << std::endl;
    std::srand(static_cast<unsigned int>(std::time(0)));
    int random_number = std::rand() % 2;
    if (random_number == 0)
        std::cout << target << " has been robotomized successfull." << std::endl;
    else
        std::cout << "The robotomy failed." << std::endl;

}

RobotomyRequestForm& RobotomyRequestForm :: operator= ( const RobotomyRequestForm & other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

RobotomyRequestForm :: RobotomyRequestForm ( const RobotomyRequestForm & other) : AForm(other)
{
    return ;
}

RobotomyRequestForm :: ~RobotomyRequestForm ( void )
{
    std::cout << "RobotomyRequestForm destructor!" << std::endl;
}

void RobotomyRequestForm :: executee ( void ) const
{
    std::cout << "Im the Robotomy Request Form !!!" << std::endl;
}
