#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


int main( void )
{
    Base *tmp1 = new Base;
    Base *tmpa = new A;
    Base *tmpb = new B;
    Base *tmpc = new C;

    std::cout << "\nIDENTIFY TEST:" << std::endl;

    tmp1->identify(tmpa);
    tmp1->identify(tmpb);
    tmp1->identify(tmpc);

    std::cout << "\nGENERATE test:" << std::endl;

    Base *tmpg =  tmp1->generate();
    Base *tmpg1 = tmp1->generate();
    Base *tmpg2 = tmp1->generate();
    tmp1->identify(tmpg);
    tmp1->identify(tmpg1);
    tmp1->identify(tmpg2);

    A a;
    B b;
    C c;

    std::cout << "\n IDENTIFY&p test:" << std::endl;

    tmp1->identify(a);
    tmp1->identify(b);
    tmp1->identify(c);
    delete tmp1;
    delete tmpa;
    delete tmpb;
    delete tmpc;
    delete tmpg;
    delete tmpg1;
    delete tmpg2;


    return (0);
}
