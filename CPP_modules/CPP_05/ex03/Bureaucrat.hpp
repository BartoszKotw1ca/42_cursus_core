#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

// #include "header.h"

#include <iostream>
#include <string>
#include <exception>
#define RED "\033[31m"
#define OR "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
class Bureaucrat;
#include "AForm.hpp"

class Bureaucrat
{
    public:
        Bureaucrat ( std::string name, int grade );
        ~Bureaucrat ( void );
        Bureaucrat& operator = ( const Bureaucrat &other);
        Bureaucrat ( const Bureaucrat &other);
        std::string    getName( void ) const;
        int            getGrade( void ) const;
        void    increment( void );
        void    decrement( void );
        class GradeTooHighException : public std::exception
        {
            public:
                GradeTooHighException ( const std::string &message ) : _message( message ) {};
                virtual ~GradeTooHighException ( void ) throw () {};
                const char *what() const throw () { return _message.c_str();}
            private:
                std::string _message;
        } ;
        class GradeTooLowException : public std::exception
        {
            public:
                GradeTooLowException ( const std::string &message ) : _message( message ) { };
                virtual ~GradeTooLowException( void ) throw () {};
                const char *what() const throw () { return _message.c_str();}
            private:
                std::string _message;
        } ;
        void    signForm ( AForm &form );
        void    executeForm ( AForm const & form ) const;
    private:
        std::string const   _name;
        int                 _grade;
} ;

std::ostream    &operator<<(std::ostream & out, const Bureaucrat & bureaucrat);

#endif
