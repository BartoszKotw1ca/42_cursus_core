#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    public:
        Brain ( void );
        ~Brain ( void );
        Brain ( const Brain &other );
        Brain &operator = ( const Brain &other );
    private:
        std::string _ideas[100];
};

#endif