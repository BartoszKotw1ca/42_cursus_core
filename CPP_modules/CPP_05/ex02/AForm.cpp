#include "AForm.hpp"

AForm :: AForm ( const std::string name, const int reqGrade, const int excGrade ) :
_name(name), _reqGrade(reqGrade), _excGrade(excGrade)
{
    try
    {
        if (_reqGrade < 1 || _excGrade < 1)
            throw AForm::GradeTooHightException();
        else if (_reqGrade > 150 || _excGrade > 150)
            throw AForm::GradeTooLowException();
    }
    catch (std::exception & e)
    {
        std::cout << RED << e.what() << OR << std::endl;
    }
    this->_isSigned = 0;
    std::cout << CYAN << "Default AForm constructor." << OR << std::endl;
}

AForm :: ~AForm ( void )
{
    std::cout << "Default AForm destructor." << std::endl;
}

AForm& AForm::operator= ( const AForm &other)
{
    std::cout << "AForm copy operator called!" << std::endl;
    if (this != &other)
    {
        if (other.getReqGrade() <= 0 || other.getExcGrade() <= 0)
            throw AForm::GradeTooHightException();
        else if (other.getReqGrade() > 150 || other.getExcGrade() > 150)
            throw AForm::GradeTooLowException();
        // this->_name = other.getName();
        this->_isSigned = other.getSigned();
        // this->_excGrade = other.getExcGrade();
        // this->_reqGrade = other.getReqGrade();
    }
    return (*this);
}

AForm :: AForm ( const AForm &other ) : _name(other._name), _reqGrade(other._reqGrade), _excGrade(other._excGrade), _isSigned(other._isSigned)
{
    std::cout << "Bureaucrat copy constructor called!!" << std::endl;
}

std::string AForm::getName( void ) const
{
    return (this->_name);
}

bool AForm::getSigned ( void ) const
{
    return (this->_isSigned);
}

int   AForm::getReqGrade( void ) const
{
    return (this->_reqGrade);
}

int   AForm::getExcGrade( void ) const
{
    return (this->_excGrade);
}

void    AForm::beSigned( const Bureaucrat & bureaucrat )
{
    if (bureaucrat.getGrade() <= _reqGrade)
        this->_isSigned = 1;
    if (bureaucrat.getGrade() > 150)
        throw AForm::GradeTooLowException();
}

void    AForm::executee( void ) const
{
    std::cout << "Im the AForm!!" << std::endl;
}

void    AForm::execute(Bureaucrat const & executor) const
{
    if (!this->_isSigned)
        throw std::string("the form is not signed.");
    else if (executor.getGrade() > this->_excGrade)
        throw std::string("grade is to low.");
    this->executee();
}

std::ostream	&operator<<(std::ostream & out, const AForm & AForm)
{
    out << AForm.getName() << ", AForm Req grade " << AForm.getReqGrade() 
    << " exc grade " << AForm.getExcGrade() << " and the sign "
    << AForm.getSigned() << std::endl;
    return (out);
}
