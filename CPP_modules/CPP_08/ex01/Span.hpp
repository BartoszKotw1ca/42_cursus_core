#pragma once

#include <vector>
#include <iostream>
#include <list>
#include <cmath>

class Span
{
    public:
        Span ( unsigned int N );
        ~Span ( void );
        // Span ( const Span & other );
        // Span & operator = ( const Span & other );
        void addNumber( int number );
        int shortestSpan ( void );
        int longestSpan( void );
        void    print_num( void );
        void    add_more_num( unsigned int size );
        class NotEnoughSpaceException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        } ;
        class NotEnoughNumbersToCompare : public std::exception
        {
            public:
                virtual const char * what() const throw();
        } ;
    private:
        unsigned int _v_size;
        std::vector<int> _numbers;
} ;
