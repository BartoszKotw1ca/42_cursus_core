#pragma once

#include <vector>
#include <iostream>
#include <list>

template <typename T>
class Span
{
    public:
        Span ( unsigned int N );
        ~Span ( void );
        // Span ( const Span & other );
        // Span & operator = ( const Span & other );
        void addNumber( T number );
        // T shortestSpan ( void );
        // T longestSpan( void );
    private:
        unsigned int _v_size;
} ;
