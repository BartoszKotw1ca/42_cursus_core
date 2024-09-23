#pragma once

#include <iostream>

template <typename T>
void iter(T *array, int len, void (*fun)(T &var))
{
    for (int i = 0; i < len; i++)
        fun(array[i]);
}
