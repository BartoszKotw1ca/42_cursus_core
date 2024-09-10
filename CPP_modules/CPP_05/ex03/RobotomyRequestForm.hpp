#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm ( std::string target);
        ~RobotomyRequestForm ( void );
        // RobotomyRequestForm & operator= ( const RobotomyRequestForm & other);
        // RobotomyRequestForm ( const RobotomyRequestForm & other);
        virtual void executee( void ) const;
} ;

#endif
