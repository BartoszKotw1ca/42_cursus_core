#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm ( const std::string target );
        ~ShrubberyCreationForm ( void );
        // ShrubberyCreationForm ( const ShrubberyCreationForm& other);
        // ShrubberyCreationForm& operator=( const ShrubberyCreationForm & other);
        virtual void executee( void ) const;
} ;

#endif
