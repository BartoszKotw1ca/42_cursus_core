#pragma once

#include <iostream>
#include <stack>

class RPN
{
    public:
        RPN ( void );
        ~RPN ( void );
        RPN ( const RPN & other );
        RPN & operator = ( const RPN & other );
        int check_input( char* input, int ac );
        int algorithm ( void );
        // int sum ( int a, int b, int res )
    private:
        std::stack<int> _stack;
        std::string     _values;
};

