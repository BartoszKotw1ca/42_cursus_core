#include <iostream>
#include <map>

#ifndef HARL_HPP
# define HARL_HPP

class Harl
{
public:
    void complain ( std::string level );
    std::map < std::string, void ( Harl::*)( void ) > complaints;
    Harl ( void );
private:
    void debug ( void );
    void info ( void );
    void warning ( void );
    void error ( void );
} ;

#endif
