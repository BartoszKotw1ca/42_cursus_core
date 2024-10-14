#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <deque>
#include <set>

template <typename T>
class PmergeMe
{
    public:
        PmergeMe( );
        PmergeMe( T & arr);
        // ~PmergeMe ( void );
        // PmergeMe & operator = (const PmergeMe & other );
        // PmergeMe ( const PmergeMe & other );
    
        void printVector(const T& arr);
        void mergeInsertionSort(T& arr);
        T random_list(long unsigned int size, int max1);
        int check_if_sorted(T arr, int check_box);
        void random_test(int en);
        void easy_test(void);
        void print_info(long unsigned int size, std::string what, float time);
    private:
        T _lista;
} ;

template <typename T>
PmergeMe<T> :: PmergeMe ( void )
{
}

template <typename T>
PmergeMe<T> :: PmergeMe  ( T & arr ) : _lista(arr) 
{}

template <typename T>
void PmergeMe<T> :: printVector(const T& arr)
{
    for (typename T::const_iterator it = arr.begin(); it != arr.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename T>
// Funkcja do rekurencyjnego sortowania większych elementów
void PmergeMe<T> :: mergeInsertionSort(T& arr)
{
    int n = arr.size();
    if (n <= 1)
        return;  // Warunek zakończenia rekurencji
    // Podział na mniejsze i większe elementy
    T largerElements, smallerElements;
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
    T sortedSequence;
    std::merge(smallerElements.begin(), smallerElements.end(),
               largerElements.begin(), largerElements.end(),
               std::back_inserter(sortedSequence));
    // Przepisanie wyników do oryginalnej tablicy
    arr = sortedSequence;
}

template <typename T>
T PmergeMe<T> :: random_list(long unsigned int size, int max1)
{
    std::set<int> ran_set;
    long long int min = 0;
    long long int max = max1;
    // long long int max = 9223372036854775807;
    srand(time(0));

    while (ran_set.size() < size)
        ran_set.insert(min + rand() % (max - min + 1));

    T ran(ran_set.begin(), ran_set.end());
    std::random_shuffle(ran.begin(), ran.end());
    return ran;
}

template <typename T>
int PmergeMe<T> :: check_if_sorted(T arr, int check_box)
{
    long long int start = *arr.begin();
    for (typename T::const_iterator it = arr.begin() + 1; it != arr.end(); ++it)
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

template <typename T>
void PmergeMe<T> :: random_test(int en)
{
    int el = en;
    T rand_el = random_list(el, 10000);
    for (long unsigned int i = 0; i < rand_el.size(); i ++)
    {   
        long long int num_of_el = rand_el[i];
        std::cout << "Number of elements: " << num_of_el << std::endl;
        T arr = random_list(num_of_el, num_of_el + 1);
        if (check_if_sorted(arr, 0) == 0)
            this->mergeInsertionSort(arr);
        std::cout << (check_if_sorted(arr, 1)==1 ? "✅" : "❌") << std::endl;
    }
}

template <typename T>
void PmergeMe<T> :: easy_test(void)
{
    for (int i = 1; i <= 1000000; i *= 10)
    {   
        std::cout << "Number of elements: " << i << std::endl;
        T arr = random_list(i, 1000001);
        if (check_if_sorted(arr, 0) == 0)
            this->mergeInsertionSort(arr);
        std::cout << (check_if_sorted(arr, 1)==1 ? "✅" : "❌") << std::endl;
    }
}

template<typename T>
void PmergeMe<T> :: print_info( long unsigned int size, std::string what, float time )
{
    std::cout << "Time to process a range of " << size << " elements with "
    << what << " : " << time << " us" << std::endl;
}
