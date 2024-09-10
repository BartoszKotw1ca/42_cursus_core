#ifndef AFORM_HPP
#define AFORM_HPP

class AForm;
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
// #include "header.h"

class AForm
{
public:
    AForm ( const std::string name, const int reqGrade, const int excGrade );
    ~AForm ( void );
    AForm& operator= ( const AForm &other);
    AForm ( const AForm &other);
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
    virtual void    executee( void ) const;
    void    execute(Bureaucrat const & executor) const;
private:
    const std::string _name;
    const int _reqGrade;
    const int _excGrade;
    bool _isSigned;
} ;

std::ostream    &operator<<(std::ostream & out, const AForm & AForm);

#endif
