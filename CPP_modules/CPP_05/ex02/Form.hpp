#ifndef FORM_HPP
#define FORM_HPP

class Form;

#include "Bureaucrat.hpp"
// #include "header.h"

class Form
{
public:
    Form ( const std::string name, const int reqGrade, const int excGrade );
    ~Form ( void );
    Form& operator= ( const Form &other);
    Form ( const Form &other);
    class GradeTooHightException : public std::exception
    {
        public:
            GradeTooHightException () {}
            virtual ~GradeTooHightException() throw () {}
            const char *what() const throw () { return "Too High!";}
    } ;
    class GradeTooLowException : public std::exception
    {
        public:
            GradeTooLowException () {}
            virtual ~GradeTooLowException() throw () {}
            const char *what() const throw () { return "Too low!!";}
    } ;
    std::string getName( void ) const;
    bool    getSigned ( void ) const;
    int   getReqGrade( void ) const;
    int   getExcGrade( void ) const;
    void    beSigned( Bureaucrat const & bureaucrat );
private:
    const std::string _name;
    const int _reqGrade;
    const int _excGrade;
    bool _isSigned;
} ;

std::ostream    &operator<<(std::ostream & out, const Form & form);

#endif
