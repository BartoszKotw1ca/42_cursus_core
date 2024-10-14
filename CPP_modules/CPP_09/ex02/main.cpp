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

// Funkcja do rekurencyjnego sortowania większych elementów
void mergeInsertionSort(std::vector<int>& arr)
{
    int n = arr.size();
    if (n <= 1)
        return;  // Warunek zakończenia rekurencji

    // Podział na mniejsze i większe elementy
    std::vector<int> largerElements, smallerElements;
    for (int i = 0; i < n / 2; ++i) {
        if (arr[2 * i] > arr[2 * i + 1]) {
            largerElements.push_back(arr[2 * i]);
            smallerElements.push_back(arr[2 * i + 1]);
        } else {
            largerElements.push_back(arr[2 * i + 1]);
            smallerElements.push_back(arr[2 * i]);
        }
    }

    // Jeśli liczba elementów jest nieparzysta, dodaj ostatni element do smallerElements
    if (n % 2 != 0)
        smallerElements.push_back(arr.back());

    // Rekurencyjne sortowanie obu wektorów
    mergeInsertionSort(smallerElements);
    mergeInsertionSort(largerElements);

    // Scalenie posortowanych elementów
    std::vector<int> sortedSequence;
    std::merge(smallerElements.begin(), smallerElements.end(),
               largerElements.begin(), largerElements.end(),
               std::back_inserter(sortedSequence));

    // Przepisanie wyników do oryginalnej tablicy
    arr = sortedSequence;
}

void printVector(const std::vector<int>& arr) {
    for (std::vector<int>::const_iterator it = arr.begin(); it != arr.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

std::vector<int> random_list(long unsigned int size, int max1)
{
    std::set<int> ran_set;
    long long int min = 0;
    long long int max = max1;
    // long long int max = 9223372036854775807;
    srand(time(0));

    while (ran_set.size() < size)
        ran_set.insert(min + rand() % (max - min + 1));

    std::vector<int> ran(ran_set.begin(), ran_set.end());
    std::random_shuffle(ran.begin(), ran.end());
    return ran;
}

int check_if_sorted(std::vector<int> arr, int check_box)
{
    long long int start = *arr.begin();
    for (std::vector<int>::const_iterator it = arr.begin() + 1; it != arr.end(); ++it)
    {
        long long int end = *it;
        if (start >= end)
        {
            if (check_box)
                std::cout << start <<  " " << end << std::endl;
            return (0);
        }
        start = *it;
    }
    return (1);
}

void easy_test(void)
{
    for (int i = 1; i <= 1000000; i *= 10)
    {   
        std::cout << "Number of elements: " << i << std::endl;
        std::vector<int> arr = random_list(i, 1000001);
        if (check_if_sorted(arr, 0) == 0)
            mergeInsertionSort(arr);
        std::cout << (check_if_sorted(arr, 1)==1 ? "✅" : "❌") << std::endl;
    }
}

void random_test(int en)
{
    int el = en;
    std::vector <int> rand_el = random_list(el, 10000);
    for (long unsigned int i = 0; i < rand_el.size(); i ++)
    {   
        long long int num_of_el = rand_el[i];
        std::cout << "Number of elements: " << num_of_el << std::endl;
        std::vector<int> arr = random_list(num_of_el, num_of_el + 1);
        if (check_if_sorted(arr, 0) == 0)
            mergeInsertionSort(arr);
        std::cout << (check_if_sorted(arr, 1)==1 ? "✅" : "❌") << std::endl;
    }
}

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

    // Tests
    // easy_test();
    // random_test(100);
    return 0;
}
