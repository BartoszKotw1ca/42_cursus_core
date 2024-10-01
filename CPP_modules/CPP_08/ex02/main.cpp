#include "MutantStack.hpp"

void test_for_list(void)
{
    std::list<int> mstack;
    mstack.push_front(5);
    mstack.push_front(17);
    std::cout << *(mstack.begin()) << std::endl;
    mstack.pop_front();
    std::cout << mstack.size() << std::endl;
    mstack.push_front(3);
    mstack.push_front(5);
    mstack.push_front(737);
    // //[...]
    mstack.push_front(0);
    std::list<int>::iterator ite = --mstack.begin();
    std::list<int>::iterator it = --mstack.end();
    // ++it;
    // --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        --it;
    }
    // std::list<int> s(mstack);
}

void test_for_my_code( void )
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    // std::stack<int> s(mstack);
}

int main()
{
    test_for_list();
    std::cout << std::endl;
    test_for_my_code();
}
