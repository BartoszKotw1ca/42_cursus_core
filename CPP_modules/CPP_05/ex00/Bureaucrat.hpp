#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    public:
        Bureaucrat ( std::string name, int grade );
        ~Bureaucrat ( void );
        Bureaucrat& operator = ( const Bureaucrat &other);
        Bureaucrat ( const Bureaucrat &other);
        void    getName( void );
        void    getGrade( void );
    private:
        std::string const   _name;
        int                 _grade;
} ;

#endif
