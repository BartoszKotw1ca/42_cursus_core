#include "Span.hpp"
template <typename T>
Span::Span ( unsigned int N ) : _v_size(N)
{
    std::cout << "Span constructo with size: " << _v_size << std::endl;
}
template <typename T>
Span::~Span ( void )
{
    std::cout << "Span destructor" << std::endl;
}
