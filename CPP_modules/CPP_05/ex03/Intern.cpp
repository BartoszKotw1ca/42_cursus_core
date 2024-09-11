#include "Intern.hpp"

Intern :: Intern ( void )
{
    std::cout << "Intern constructor!" << std::endl;
}

Intern :: ~Intern ( void )
{
    std::cout << "Intern destructor!" << std::endl;
}

Intern :: Intern ( const Intern & other)
{
    (void) other;
    return ;
}

Intern & Intern :: operator= ( const Intern & other)
{
    (void) other;
    return (*this);
}


AForm* createForm1( std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* createForm2( std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* createForm3( std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern :: makeForm ( const std::string &formName, const std::string &target )
{
    AForm* (*formCreators[])(std::string) = {createForm1, createForm2, createForm3};
    std::string formNames[] = {"RobotomyRequestForm", "PresidentialPardonForm", "ShrubberyCreationForm"};
    for (int i = 0; i < (int)(sizeof(formNames) / sizeof(formNames[0])); i ++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }
    std::cout << "Error :Form " << formName << " does not exist." << std::endl;
    return NULL;
}
