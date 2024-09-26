#include "easyfind.hpp"

int main(void)
{
    std::list<int> myList;
    int     tmp_n = 3;
    int     tmp_e = 12;

    myList.push_back(3);
    myList.push_back(2);
    myList.push_back(1);
    myList.push_front(18);
    myList.push_front(23);
    myList.push_back(28);

    int res = easyfind(myList, tmp_n);
    int res_e = easyfind(myList, tmp_e);
    std::cout << res << std::endl;
    std::cout << res_e << std::endl;
}
