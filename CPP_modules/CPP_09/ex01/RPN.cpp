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

int RPN :: algorithm ( void )
{
    int res = 0;
    int if_first = 0;
    for (unsigned int i = 0; i < _values.length(); i ++)
    {
        int a = static_cast<char> (_values[i]);
        if (std::isdigit( a ))
            this->_stack.push(a - '0');
        else if ( a == 43 )  // +
        {
            while (!_stack.empty())
            {
                res += _stack.top();
                _stack.pop();
            }
            if_first += 1;
            std::cout << "Dodawanie: " << res << std::endl;
        }
        else if ( a == 42 ) // *
        {
            int tmp_res = 1;
            while (!_stack.empty())
            {
                tmp_res *= _stack.top();
                _stack.pop();
            }
            (res += (if_first == 0) ? 1 : 0) *= tmp_res;
            std::cout << "Mnozenie: " << res << std::endl;
            if_first += 1;
        }
        else if ( a == 45 ) // -
        {
            if (!_stack.empty())
            {
                res = _stack.top();
                _stack.pop();
            }
            while (!_stack.empty())
            {
                res -= _stack.top();
                _stack.pop();
            }
            std::cout << "Odejmowanie: " << res << std::endl;
            if_first += 1;
        }
        else if ( a == 47 ) // /
        {
            while (!_stack.empty())
            {
                res /= _stack.top();
                _stack.pop();
            }
            std::cout << "Dzielenie: " << res << std::endl;
            if_first += 1;
        }
        // std::cout << a << std::endl;
        // std::cout << _values[i] << std::endl;
    }
    
    // char b = _stack.top();
    // std::cout << std::endl;
    while (!_stack.empty()) {
        std::cout << _stack.top() <<" ";
        _stack.pop();
    }
    // std::cout << b << std::endl;
    std::cout << res << std::endl;
    return (0);
}
