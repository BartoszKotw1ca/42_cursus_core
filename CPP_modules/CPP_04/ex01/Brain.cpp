#include "Brain.hpp"

Brain::Brain ( void )
{
    std::cout << "Brain constructor" << std::endl;
}

Brain::~Brain ( void )
{
    std::cout << "Brain destructor" << std::endl;
}

Brain::Brain ( const Brain &other )
{
    std::cout << "Brain copy constructor" << std::endl;
    for (int i = 0; i < 100; ++i)
        _ideas[i] = other._ideas[i];
}

Brain &Brain::operator = ( const Brain &other )
{
    std::cout << "Brain assignment operator" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            _ideas[i] = other._ideas[i];
    }
    return *this;
}