#pragma once

#include <vector>
#include <stack>
#include <iostream>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack ( void );
        ~MutantStack ( void );
        MutantStack ( const MutantStack & other );
        MutantStack & operator = ( const MutantStack & other );
        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin();
        iterator end();
};

template < typename T>
typename MutantStack<T> :: iterator MutantStack <T> ::begin() 
{
    return std::stack<T>::c.begin();
}

template < typename T>
typename MutantStack<T> :: iterator MutantStack <T> ::end() 
{
    return std::stack<T>::c.end();
}

template < typename T > 
MutantStack<T>::MutantStack( void )
{
    std::cout << "MutantStack con" << std::endl;
}

template < typename T >
MutantStack<T>::~MutantStack ( void )
{
    std::cout << "MutantStack des" << std::endl;
}

template< typename T > 
MutantStack <T> :: MutantStack ( const MutantStack & other )
{
    (void) other;
}

template < typename T>
MutantStack<T>& MutantStack<T> :: operator = (const MutantStack &other)
{
    (void) other;
    return *this;
}
