#include "PmergeMe.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <set>
#include <deque>
#include <list>

int main()
{

    std::deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_front(0);
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_front(0);

    PmergeMe<std::vector<int> > tmp_vector;
    PmergeMe<std::deque<int> > tmp_deq;
    std::vector<int> t;
    // Tests

    std::cout << "Tes" << std::endl;

    tmp_vector.easy_test();
    tmp_vector.random_test(100);

    tmp_deq.easy_test();
    tmp_deq.random_test(100);

    return 0;
}
