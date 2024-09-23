#include <iostream>
#include "iter.hpp"

void add_one(int &x)
{
    x += 1;
}

void print(int x)
{
    std::cout << x << std::endl;
}

int main(void)
{
    int array[] = {1, 2, 3, 4, 5};
    
    std::cout << "\nBefore adding one to numbers!" << std::endl;
    // iter(array, 5, print);
    
    iter(array, 5, add_one);
    
    std::cout << "\nADDED:" << std::endl;
    
    // iter(array, 5, print);
    return 0;
}
