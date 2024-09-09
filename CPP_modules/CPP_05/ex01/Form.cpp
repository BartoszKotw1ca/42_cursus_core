#include "Form.hpp"

Form :: Form ( const std::string name, const int reqGrade, const int excGrade ) :
_name(name), _reqGrade(reqGrade), _excGrade(excGrade)
{
    try
    {
        if (_reqGrade < 1 || _excGrade < 1)
            throw Form::GradeTooHightException();
        else if (_reqGrade > 150 || _excGrade > 150)
            throw Form::GradeTooLowException();
    }
    catch (std::exception & e)
    {
        std::cout << RED << e.what() << OR << std::endl;
    }
    this->_isSigned = 0;
    std::cout << "Default form constructor." << std::endl;
}

Form :: ~Form ( void )
{
    std::cout << "Default form destructor." << std::endl;
}

std::string Form::getName( void ) const
{
    return (this->_name);
}

bool Form::getSigned ( void ) const
{
    return (this->_isSigned);
}

int   Form::getReqGrade( void ) const
{
    return (this->_reqGrade);
}

int   Form::getExcGrade( void ) const
{
    return (this->_excGrade);
}

void    Form::beSigned( const Bureaucrat & bureaucrat )
{
    if (bureaucrat.getGrade() <= _reqGrade)
        this->_isSigned = 1;
    if (bureaucrat.getGrade() > 150)
        throw Form::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream & out, const Form & form)
{
    out << form.getName() << ", form Req grade " << form.getReqGrade() 
    << " exc grade " << form.getExcGrade() << " and the sign "
    << form.getSigned() << std::endl;
    return (out);
}
