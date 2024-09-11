#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern ( void );
        virtual ~Intern ( void );
        Intern ( const Intern & other);
        Intern & operator = ( const Intern & other);
        AForm* makeForm( const std::string &formName, const std::string &target);
} ;

#endif
