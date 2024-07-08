#include <iostream>

int main( void )
{
    std::string tmp_str = "HI THIS IS BRAIN";
    std::string *tmpPTR = new std::string("HI THIS IS BRAIN");
    std::cout << tmp_str;
    delete tmpPTR;
}
