#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm ( std::string target );
        ~PresidentialPardonForm ( void );
        PresidentialPardonForm & operator= ( const PresidentialPardonForm & other);
        PresidentialPardonForm ( const PresidentialPardonForm & other);
        virtual void executee( void ) const;
} ;
#endif
