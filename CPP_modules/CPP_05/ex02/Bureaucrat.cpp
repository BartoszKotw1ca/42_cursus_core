#include "Bureaucrat.hpp"

Bureaucrat :: Bureaucrat ( std::string name, int grade ) : _name ( name ),  _grade ( grade ) 
{
    try
    {
        if ( this->_grade < 1 )
        {
            this->_grade = 1;
            throw Bureaucrat::GradeTooHighException("Too high!!");
        }
        else if ( this ->_grade > 150 )
        {
            this->_grade = 150;
            throw Bureaucrat::GradeTooLowException("Too low!!!");
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

Bureaucrat& Bureaucrat :: operator = ( const Bureaucrat &other)
{
    std::cout << "Bureaucrat copy operator called!" << std::endl;
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::Bureaucrat ( const Bureaucrat &other) : _grade(other._grade)
{
    std::cout << "Bureaucrat copy constructor called!!" << std::endl;
}

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

void    Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " exec " << form.getName() << std::endl;
    }
    catch (std::string & e)
    {
        std::cout << this->_name << " can't execute " << form.getName();
        std::cout << " because " << e << std::endl;
    }
}

void    Bureaucrat::signForm( AForm &form)
{
    if (form.getSigned() == 1)
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    else
        std::cout << this->_name << " couldn't sign " << form.getName()
        << " because of the required grade" << std::endl;
}

std::ostream	&operator<<(std::ostream & out, const Bureaucrat & bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}
