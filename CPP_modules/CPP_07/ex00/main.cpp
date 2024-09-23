#include "whatever.hpp"

void test_for_swap_string(void)
{
    std::string tmp1 = "jan";
    std::string tmp2 = "kowalski";
    
    std::cout << "TMP1: "<< (tmp1=="jan") << std::endl;
    std::cout << "TMP2: "<< (tmp2=="kowalski") << std::endl;

    swap(tmp1, tmp2);

    std::cout << "After swap:" << std::endl;

    std::cout << "TMP1: "<< (tmp1=="kowalski") << std::endl;
    std::cout << "TMP2: "<< (tmp2=="jan") << std::endl;
}

void test_for_swap_int(void)
{
    int tmp1 = 32;
    int tmp2 = 23;
    
    std::cout << "TMP1: "<< tmp1 << std::endl;
    std::cout << "TMP2: "<< tmp2 << std::endl;

    swap(tmp1, tmp2);

    std::cout << "After swap:" << std::endl;

    std::cout << "TMP1: "<< tmp1 << std::endl;
    std::cout << "TMP2: "<< tmp2 << std::endl;
}

void test_for_swap_float(void)
{
    float tmp1 = 5.3f;
    float tmp2 = 3.5f;
    
    std::cout << "TMP1: "<< tmp1 << std::endl;
    std::cout << "TMP2: "<< tmp2 << std::endl;

    swap(tmp1, tmp2);

    std::cout << "After swap:" << std::endl;

    std::cout << "TMP1: "<< tmp1 << std::endl;
    std::cout << "TMP2: "<< tmp2 << std::endl;
}

void test_for_min(void)
{
    int tmp1 = 23;
    int tmp2 = 32;

    std::string tmps1 = "Baran";
    std::string tmps2 = "Agnieszka"; 
    std::string tmps3 = "Baran";

    float tmpf1 = 5.3f;
    float tmpf2 = 3.5f;

    std::cout << (::min(tmps1, tmps3)=="Baran") << std::endl;
    std::cout << (::min(tmp1, tmp2)==23) << std::endl;
    std::cout << (::min(tmps1, tmps2)=="Agnieszka") << std::endl; 
    std::cout << (::min(tmpf1, tmpf2)==3.5f) << std::endl;
}

void test_for_max(void)
{
    int tmp1 = 23;
    int tmp2 = 32;

    std::string tmps1 = "Baran";
    std::string tmps2 = "Agnieszka"; 
    std::string tmps3 = "Baran";

    float tmpf1 = 5.3f;
    float tmpf2 = 3.5f;

    std::cout << (::max(tmps1, tmps3)=="Baran") << std::endl;
    std::cout << (::max(tmp1, tmp2)==32) << std::endl;
    std::cout << (::max(tmps1, tmps2)=="Baran") << std::endl; 
    std::cout << (::max(tmpf1, tmpf2)==5.3f) << std::endl;
}

void test_from_subject(void)
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int main(void)
{
    // test_for_swap_string();
    // test_for_swap_int();
    // test_for_swap_float();

    // test_for_min();
    // test_for_max();
    test_from_subject();
    return 0;
}
