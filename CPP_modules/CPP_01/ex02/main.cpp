#include <iostream>

int main( void )
{
    std::string tmp_str = "HI THIS IS BRAIN";
    std::string *tmpPTR = &tmp_str;
    // std::string tmpcopy = tmp_str bylaby to kopia tmp_str
    std::string &tmpREF = tmp_str;

    std::cout << "str -> STR: " << &tmp_str << std::endl;
    std::cout << "str -> PTR: " << tmpPTR << std::endl;
    std::cout << "str -> REF: " << &tmpREF << std::endl;

    std::cout << "str -> STR: " << tmp_str << std::endl;
    std::cout << "str -> PTR: " << *tmpPTR << std::endl;
    std::cout << "str -> REF: " << tmpREF << std::endl;
}
