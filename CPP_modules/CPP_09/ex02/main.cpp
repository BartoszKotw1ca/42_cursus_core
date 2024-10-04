#include "PmergeMe.hpp"

// int main(void)
// {
//     std::vector<int> tmp_vec;

//     tmp_vec.push_back(10);
//     tmp_vec.push_back(11);
//     tmp_vec.push_back(13);
//     tmp_vec.push_back(11234);
//     tmp_vec.push_back(1112312);
//     tmp_vec.push_back(11234234);
//     tmp_vec.push_back(1112312);
//     tmp_vec.push_back(13575671);
//     tmp_vec.push_back(115435);
//     tmp_vec.push_back(11346456);
//     tmp_vec.push_back(1156456);
//     tmp_vec.push_back(11234234);
//     tmp_vec.push_back(154565613);
//     tmp_vec.push_back(11453453);
//     tmp_vec.push_back(1135643);
//     tmp_vec.push_back(1453451);
//     tmp_vec.push_back(1134534534);
//     tmp_vec.push_back(113453453);

//     PmergeMe tmp(tmp_vec, 15);

//     tmp.sort();

//     return (0);
// }


#include <iostream>
#include <vector>
#include <algorithm> // Dla std::copy, std::merge, std::sort
#include <iterator>  // Dla std::back_inserter

const int MIN_SIZE = 32;

// Funkcja do sortowania przez wstawianie
void insertionSort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    for (std::vector<int>::iterator it = begin + 1; it != end; ++it) {
        int key = *it;
        std::vector<int>::iterator j = it - 1;

        // Przesuwaj elementy, które są większe od klucza, w prawo
        while (j >= begin && *j > key) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = key;
    }
}

// Funkcja do scalania dwóch posortowanych podtablic
void merge(std::vector<int>::iterator left, std::vector<int>::iterator mid, std::vector<int>::iterator right) {
    std::vector<int> leftVec(left, mid + 1); // Tworzy wektor z lewą podtablicą
    std::vector<int> rightVec(mid + 1, right + 1); // Tworzy wektor z prawą podtablicą

    std::vector<int>::iterator itLeft = leftVec.begin();
    std::vector<int>::iterator itRight = rightVec.begin();
    std::vector<int>::iterator itDest = left;

    // Scalanie podtablic
    while (itLeft != leftVec.end() && itRight != rightVec.end()) {
        if (*itLeft <= *itRight) {
            *itDest++ = *itLeft++;
        } else {
            *itDest++ = *itRight++;
        }
    }

    // Skopiuj pozostałe elementy, jeśli są
    while (itLeft != leftVec.end()) {
        *itDest++ = *itLeft++;
    }
    while (itRight != rightVec.end()) {
        *itDest++ = *itRight++;
    }
}

// Funkcja do sortowania merge-insertion
void mergeInsertionSort(std::vector<int>::iterator left, std::vector<int>::iterator right) {
    if (right - left + 1 <= MIN_SIZE) {
        insertionSort(left, right + 1);
    } else {
        std::vector<int>::iterator mid = left + (right - left) / 2;
        mergeInsertionSort(left, mid);
        mergeInsertionSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main(int ac, char **av) {
    std::vector<int> arr;

    int i = 0;
    while (av[1][i])
    {
        arr.push_back(atoi(av[1][i].c_str()));
    }
    int n = arr.size();

    mergeInsertionSort(arr.begin(), arr.end() - 1);

    std::cout << "Posortowana tablica: ";
    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
