#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array
{
    public:
        Array( void ) : _n(0)
        {
            _array = NULL;
            std::cout << "Array constructor!" << std::endl;
        }
        Array( unsigned int n ) : _n(n)
        {
            _array = new T[_n];
            for (unsigned int i = 0; i < n; i ++)
            {
                _array[i] = T();
                std::cout << "Number: " << i << " Element: " <<  _array[i] << std::endl;
            }
            std::cout << "Array constructor!" << std::endl;
        }
        Array & operator = (const Array & other )
        {
            if (this != &other)
            {
                delete[] _array;
                _n = other._n;
                _array = new T[_n];
                for (unsigned int i = 0; i < _n; i ++)
                    _array[i] = other._array[i];
            }
            return (*this);
        }
        Array ( const Array & other)
        {
            _n = other._n;
            _array = new T[_n];
            for (unsigned int i = 0; i < _n; i ++)
                _array[i] = other._array[i];
        }
        ~Array ( void )
        {
            delete[] _array;
            std::cout << "Array desturctor!" << std::endl;
        }
        T& operator[](unsigned int index)
        {
            if(index >= _n || index < 0)
            {
                throw std::out_of_range("Array index out of bounds");
            }
            return _array[index];
        }
        int size ( void ) const
        {
            return _n;
        }
    private:
        T *_array;
        unsigned int _n;
} ;
