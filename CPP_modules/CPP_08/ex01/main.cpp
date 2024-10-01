#include "Span.hpp"

#include <list>
int main(void)
{
    std::vector<int> numbers;
    std::list<int> numbers_l;

    numbers_l.resize(1);
    std::cout << numbers_l.size() << std::endl;
    numbers_l.push_back(12);
    numbers_l.push_back(13);
    std::cout << numbers_l.size() << std::endl;
    numbers.reserve(3);
    numbers.push_back(10);
    numbers.push_back(11);
    numbers.push_back(12);
    std::cout << numbers.capacity() << std::endl;
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it ++)
    {
        std::cout << *it << std::endl;
    }
    return 0;
}
