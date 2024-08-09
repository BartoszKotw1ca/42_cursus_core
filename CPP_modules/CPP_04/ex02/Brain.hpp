#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animals.h"

class Brain
{
    public:
        Brain ( void ) { std::cout << "Brain constructor" << std::endl; };
        ~Brain ( void ) { std::cout << "Brain destructor" << std::endl; };
        Brain ( const Brain &other )
        {
            std::cout << "Brain copy constructor" << std::endl;
            for (int i = 0; i < 100; ++i)
                _ideas[i] = other._ideas[i];
        }
        Brain &operator = ( const Brain &other)
        {
            std::cout << "Brain assignment operator" << std::endl;
            if (this != &other)
            {
                for (int i = 0; i < 100; ++ i)
                    _ideas[i] = other._ideas[i];
            }
            return *this;
        }
    private:
        std::string _ideas[100];
} ;

#endif