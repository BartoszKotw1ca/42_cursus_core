#include "Span.hpp"

#include <list>
// int main(void)
// {
//     std::vector<int> numbers;
//     std::list<int> numbers_l;

//     numbers_l.resize(1);
//     std::cout << numbers_l.size() << std::endl;
//     numbers_l.push_back(12);
//     numbers_l.push_back(13);
//     std::cout << numbers_l.size() << std::endl;
//     numbers.reserve(3);
//     numbers.push_back(10);
//     numbers.push_back(11);
//     numbers.push_back(12);
//     std::cout << numbers.capacity() << std::endl;
//     for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it ++)
//     {
//         std::cout << *it << std::endl;
//     }
//     return 0;
// }

void test_for_max_cap(void)
{
    Span tmp(100000);

    int t1 = 23;
    // int t2 = 52;
    // int t3 = -32;
    // int t4 = 0;

    try
    {
        for (int i = 0; i < 100001; i ++)
            tmp.addNumber(t1);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    // tmp.print_num();
}

void    test_for_min_and_max(void)
{
    Span tmp(10000);
    try
    {
        std::cout << "Shortest span: " << tmp.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (unsigned int i = 0; i < 10000; i ++)
    {
        int tmp1 = i;
        tmp.addNumber(tmp1);
    }
    std::cout << "Shortest span: " << tmp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << tmp.longestSpan() << std::endl;
}

void    test_from_subj(void)
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

int main(void)
{
    // test_for_max_cap();
    // test_for_min_and_max();
    // test_from_subj();
    Span    tm(10);

    tm.add_more_num(10);
    tm.print_num();
}
