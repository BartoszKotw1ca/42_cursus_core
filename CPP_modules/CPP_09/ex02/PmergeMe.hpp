#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <deque>

class PmergeMe
{
    public:
        PmergeMe(std::vector<int> & input, int size);
        ~PmergeMe ( void );
        PmergeMe & operator = (const PmergeMe & other );
        PmergeMe ( const PmergeMe & other );
        void sort( void );
    private:
        std::vector<int>    _vector;
        std::deque<int>   _deque;
        const int         _size;

} ;
