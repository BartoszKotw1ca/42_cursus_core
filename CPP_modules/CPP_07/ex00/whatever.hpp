#pragma once

#include <iostream>

template <typename T>
void swap(T &value1, T &value2)
{
    T tmp;

    tmp = value1;
    value1 = value2;
    value2 = tmp;
}

template <typename T>
T min(T value1, T value2)
{
    if (value1 < value2)
        return value1;
    if (value2 < value1)
        return value2;
    else
        return value2;
}

template <typename T>
T max(T value1, T value2)
{
    if (value1 < value2)
        return value2;
    if (value2 < value1)
        return value1;
    else
        return value2;
}
