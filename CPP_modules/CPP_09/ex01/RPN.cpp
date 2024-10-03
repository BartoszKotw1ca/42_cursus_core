#include "RPN.hpp"

RPN :: RPN ( void )
{}

RPN :: ~RPN ( void )
{}

RPN & RPN :: operator = ( const RPN & other )
{
    if (this != &other)
    {
        this->_stack = other._stack;
    }
    return *this;
}

RPN :: RPN ( const RPN & other )
{
    this->_stack = other._stack;
}

int RPN :: check_input ( char* input, int ac )
{
    std::string av = input;
    std::string valid_chars = "0123456789+-/* ";
    if (ac != 2
        || av.find_first_not_of(valid_chars) != std::string::npos)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }
    this->_values = av;
    return (0);
}

void RPN :: write_a_b ( void )
{
    if (_stack.empty())
    {
        std::cout << "Error" << std::endl;
        this->_err_val = 1;
        return ;
    }
    this->_a = _stack.top();
    _stack.pop();

    if (_stack.empty())
    {
        std::cout << "Error" << std::endl;
        this->_err_val = 1;
        return ;
    }
    this->_b = _stack.top();
    _stack.pop();
}

int RPN :: algorithm ( void )
{
    this->_err_val = 0;
    for (unsigned int i = 0; i < _values.length(); i ++)
    {
        if (this->_err_val == 1)
            break;
        int a = static_cast<char> (_values[i]);
        if (std::isdigit( a ))
            this->_stack.push(a - '0');
        else if ( a == 43 )  // +
        {
            write_a_b();
            _stack.push(_a + _b);
            std::cout << "Dodawanie: " << _stack.top() << std::endl;
        }
        else if ( a == 42 ) // *
        {
            write_a_b();
            _stack.push(_a * _b);
            std::cout << "Mnozenie: " << _stack.top() << std::endl;
        }
        else if ( a == 45 ) // -
        {
            write_a_b();
            _stack.push(_b - _a);
            std::cout << "Odejmowanie: " << _stack.top() << std::endl;
        }
        else if ( a == 47 ) // /
        {
            write_a_b();
            _stack.push(_b / _a);
            std::cout << "Dzielenie: " << _stack.top() << std::endl;
        }
    }
    if (this->_err_val == 1)
        return (1);
    if(!_stack.empty())
        std::cout << _stack.top() << std::endl;
    else
        std::cout << "Error" << std::endl;
    return (0);
}
