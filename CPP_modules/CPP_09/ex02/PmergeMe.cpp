#include "PmergeMe.hpp"

PmergeMe :: PmergeMe (std::vector<int> & input, int size) : _vector(input), _deque(input.begin(), input.end()), _size(size)
{}

PmergeMe :: ~PmergeMe ( void )
{}

PmergeMe :: PmergeMe ( const PmergeMe & other ) : _size(other._size)
{
    (void) other;
    return ;
}

PmergeMe & PmergeMe :: operator = ( const PmergeMe & other )
{
    (void) other;
    return *this;
}

void PmergeMe :: sort ( void )
{
clock_t start = clock();
	
	std::deque<int>::iterator	it = this->_deque.begin();
	std::deque<int>::iterator	ite = this->_deque.end();

	size_t const				half_size = this->_deque.size() / 2;
	std::deque<int>				split_lo;
	std::deque<int>				split_hi;

	for (size_t i = 0; i < half_size; i++) {
		split_lo.push_back(*it);
		it++;
	}
	for (; it != ite; it++)
		split_hi.push_back(*it);

	std::sort(split_lo.begin(), split_lo.end());
	std::sort(split_hi.begin(), split_hi.end());

	split_lo.insert(split_lo.end(), split_hi.begin(), split_hi.end());

	std::sort(split_lo.begin(), split_lo.end());

	clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << this->_size << " elements with std::deque<int> : " << duration << " us" << std::endl;
}
