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
        void write_a_b( void );
    private:
        std::stack<float> _stack;
        std::string     _values;
        int             _a;
        int             _b;
        int             _err_val;
};

