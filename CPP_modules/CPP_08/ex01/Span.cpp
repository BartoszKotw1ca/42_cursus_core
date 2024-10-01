#include "Span.hpp"

Span::Span ( unsigned int N ) : _v_size(N)
{
    std::cout << "Span constructo with size: " << _v_size << std::endl;
}

Span::~Span ( void )
{
    std::cout << "Span destructor" << std::endl;
}

void    Span::addNumber(int number)
{
    if (this->_v_size <= _numbers.size())
        throw NotEnoughSpaceException();
    else
        this->_numbers.push_back(number);
}

const char * Span::NotEnoughSpaceException::what ( ) const throw()
{
    return ("There is not enought space for numbers!!");
}

void Span::print_num ( void )
{
    for (std::vector<int>::iterator it = _numbers.begin(); it != _numbers.end(); it ++)
    {
        std::cout << *it << std::endl;
    }
}

const char * Span::NotEnoughNumbersToCompare::what() const throw()
{
    return ("There is not enoguth numbers to compare!");
}

int Span::longestSpan( void )
{
    int s_span;

    s_span = -1;
    for (unsigned int i = 0; i < _numbers.size(); i ++)
    {
        for(unsigned int j = 0; j < _numbers.size(); j ++)
        {
            int tmp = _numbers[i] - _numbers[j];
            if (s_span < std::abs(tmp))
                s_span = tmp;
        }
    }
    if (s_span == -1 || this->_numbers.size() == 1)
        throw NotEnoughNumbersToCompare();
    return std::abs(s_span);
}

int Span::shortestSpan( void )
{
    int s_span;

    if (this->_numbers.size() <= 1)
        throw NotEnoughNumbersToCompare();
    s_span = std::abs(_numbers[0] - _numbers[1]);
    for (unsigned int i = 0; i < _numbers.size(); i ++)
    {
        for(unsigned int j = 0; j < _numbers.size(); j ++)
        {
            int tmp = _numbers[i] - _numbers[j];
            if (j != i && s_span > std::abs(tmp))
                s_span = tmp;
        }
    }
    return std::abs(s_span);
}

void    Span::add_more_num( unsigned int size )
{
    for (unsigned int i = 0; i < size; i ++)
    {
        int tmp1 = i;
        this->addNumber(tmp1);
    }
}
