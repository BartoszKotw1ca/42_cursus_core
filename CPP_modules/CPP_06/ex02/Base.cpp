#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base ( void )
{
    std::cout << "Base Destructor!" << std::endl;
}

Base *Base::generate ( void )
{
    srand(time(0));
    int r_num = rand() % 3 + 1;
    Base *tmp = NULL;
    switch ( r_num )
    {
        case 1:
            tmp = new A;
            return (tmp);
            break;
        case 2:
            tmp = new B;
            return (tmp);
            break;
        case 3:
            tmp = new C;
            return (tmp);
            break;
    }
    return (tmp);
}

void Base::identify ( Base * p)
{
    if (dynamic_cast<A*>(p) != 0)
        std::cout << "This is the A class." << std::endl;
    if (dynamic_cast<B*>(p) != 0)
        std::cout << "This is the B class." << std::endl;
    if (dynamic_cast<C*>(p) != 0)
        std::cout << "This is the C class." << std::endl;
}

void Base::identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void) a;
        std::cout << "This is the A class." << std::endl;
    } catch (std::exception &e) {}

    try {
        B& b = dynamic_cast<B&>(p);
        (void) b;
        std::cout << "This is the B class." << std::endl;
    } catch (std::exception &e) {}

    try {
        C& c = dynamic_cast<C&>(p);
        (void) c;
        std::cout << "This is the C class." << std::endl;
    } catch (std::exception &e) {}
}
