#include "Bureaucrat.hpp"

Bureaucrat :: Bureaucrat ( std::string name, int grade ) : _name ( name ),  _grade ( grade ) 
{
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
    std::cout << "Bureaucrat copy consturctor called!" << std::endl;
    
}
