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
#include <sys/time.h>

void test_algo(void)
{
    PmergeMe<std::vector<int> > tmp_vector;
    PmergeMe<std::deque<int> > tmp_deq;
    // Tests

    std::cout << "Tes" << std::endl;

    tmp_vector.easy_test();
    tmp_vector.random_test(100);

    tmp_deq.easy_test();
    tmp_deq.random_test(100);
}

float info_for_deque(char **av, PmergeMe<std::deque<int> > tmp_deq_c)
{
    struct timeval start, end;
    long seconds, useconds;
    float time;

    gettimeofday(&start, NULL);

    std::deque<int> tmp_deq;
    int i = 0;
    while (av[++i])
        tmp_deq.push_back(atoi(av[i]));
    tmp_deq_c.mergeInsertionSort(tmp_deq);

    gettimeofday(&end, NULL);
    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    time = ((seconds) * 1000000 + useconds);

    return time;
}

float info_for_vector(char **av, PmergeMe<std::vector<int> > tmp_vec_c)
{
    struct timeval start, end;
    long seconds, useconds;
    float time;

    gettimeofday(&start, NULL);

    std::vector<int> tmp_vector;
    int i = 0;
    while (av[++i])
        tmp_vector.push_back(atoi(av[i]));
    tmp_vec_c.mergeInsertionSort(tmp_vector);

    gettimeofday(&end, NULL);
    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    time = ((seconds) * 1000000 + useconds);

    return time;
}


int main(int ac, char **av)
{

    if (ac == 1)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }

    std::vector<int> tmp_vector;
    std::set<int> ran_set;
    int i = 0;
    while(av[++ i])
    {
        tmp_vector.push_back(atoi(av[i]));
        ran_set.insert(atoi(av[i]));
    }

    PmergeMe<std::vector<int> > tmp_vector_c;
    PmergeMe<std::deque<int> > tmp_deq_c;

    if (tmp_vector_c.check_if_sorted(tmp_vector, 0) || tmp_vector.size() != ran_set.size())
    {
        std::cout << "Error" << std::endl;
        return (1);
    }

    std::cout << "Before: ";
    tmp_vector_c.printVector(tmp_vector);
    std::cout << "After: ";
    for (std::set<int>::iterator it = ran_set.begin(); it != ran_set.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    float time_vec = info_for_vector(av, tmp_vector_c);
    tmp_vector_c.print_info(tmp_vector.size(), "std::vector", time_vec);
    float time_deq = info_for_deque(av, tmp_deq_c);
    tmp_deq_c.print_info(tmp_vector.size(), "std::deque", time_deq);
    // test_algo();
    return 0;
}
