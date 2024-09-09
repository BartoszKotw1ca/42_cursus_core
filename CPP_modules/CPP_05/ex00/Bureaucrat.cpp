#include "Bureaucrat.hpp"

Bureaucrat :: Bureaucrat ( std::string name, int grade ) : _name ( name ),  _grade ( grade ) 
{
    try
    {
        if ( this->_grade < 1 )
        {
            this->_grade = 1;
            throw GradeTooHighException("Too high!!");
        }
        else if ( this ->_grade > 150 )
        {
            this->_grade = 150;
            throw GradeTooLowException("Too low!!!");
        }
    }
    catch (std::exception & e)
    {
        std::cout << RED << e.what() << OR << std::endl;
    }
    std::cout << "Bureaucrat " << _name
    << " with grade " << _grade
    << " constructor called!" << std::endl;
}

Bureaucrat :: ~Bureaucrat( void )
{
    std::cout << "Bureaucrat " << _name
    << " with grade " << _grade
    << " destructor called!" << std::endl;
}

// Bureaucrat& Bureaucrat :: operator = ( const Bureaucrat &other)
// {
    // std::cout << "Bureaucrat copy consturctor called!" << std::endl;
    // (void ) other;
// }

std::string    Bureaucrat :: getName ( void ) const
{
    return this->_name;
}

int     Bureaucrat :: getGrade ( void ) const
{
    return this->_grade;
}

void    Bureaucrat :: increment ( void )
{
    if (this->_grade > 1)
        this->_grade -= 1;
}

void    Bureaucrat :: decrement ( void )
{
    if (this->_grade < 150)
        this->_grade += 1;
}

std::ostream	&operator<<(std::ostream & out, const Bureaucrat & bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}
