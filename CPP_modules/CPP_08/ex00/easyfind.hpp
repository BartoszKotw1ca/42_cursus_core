#pragma once

#include <iostream>
#include <list>


// it is returning the index in the list
template <typename T>
int easyfind (const T &lista, int &to_find)
{
    int i = 0;
    typename T::const_iterator it;
    for (it = lista.begin(); it != lista.end(); ++it)
    {
        if (*it == to_find)
            return i;
        i ++;
    }
    return (-1);
}
