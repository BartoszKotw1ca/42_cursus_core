#include "Bureaucrat.hpp"
#include "Form.hpp"

void    TestForBureaucrat( void )
{
    Bureaucrat tmp1("Janusz", 0);
    Bureaucrat tmp2("Janusz1", 151);
    Bureaucrat tmp3("Janusz3", 15);

    std::cout << "Name: " << tmp1.getName() << std::endl;
    std::cout << "Name: " << tmp2.getName() << std::endl;
    std::cout << "Name: " << tmp3.getName() << std::endl;

    std::cout << "Grade: " << tmp1.getGrade() << std::endl;
    std::cout << "Grade: " << tmp2.getGrade() << std::endl;
    std::cout << "Grade: " << tmp3.getGrade() << std::endl;

    std::cout << "Decrementing :" << std::endl;

    tmp1.decrement();
    tmp2.decrement();
    tmp3.decrement();

    std::cout << "Grade: " << tmp1.getGrade() << std::endl;
    std::cout << "Grade: " << tmp2.getGrade() << std::endl;
    std::cout << "Grade: " << tmp3.getGrade() << std::endl;

    std::cout << "Incrementing :" << std::endl;

    tmp1.increment();
    tmp2.increment();
    tmp3.increment();

    std::cout << "Grade: " << tmp1.getGrade() << std::endl;
    std::cout << "Grade: " << tmp2.getGrade() << std::endl;
    std::cout << "Grade: " << tmp3.getGrade() << std::endl;

    std::cout << tmp1;
    std::cout << tmp2;
    std::cout << tmp3;
}

int main ( void )
{
    Form tmp1("Tmp1", 10, 50);
    Form tmp2("Tmp2", 0, 20);
    Form tmp3("Tmp3", 151, 151);

    std::cout << "Name: " << tmp1.getName() << std::endl;
    std::cout << "Name: " << tmp2.getName() << std::endl;
    std::cout << "Name: " << tmp3.getName() << std::endl;

    std::cout << "Signed: " << tmp1.getSigned() << std::endl;
    std::cout << "Signed: " << tmp2.getSigned() << std::endl;
    std::cout << "Signed: " << tmp3.getSigned() << std::endl;
    
    std::cout << "Required Grade: " << tmp1.getReqGrade() << std::endl;
    std::cout << "Required Grade: " << tmp2.getReqGrade() << std::endl;
    std::cout << "Required Grade: " << tmp3.getReqGrade() << std::endl;

    std::cout << "Execute Grade: " << tmp1.getExcGrade() << std::endl;
    std::cout << "Execute Grade: " << tmp2.getExcGrade() << std::endl;
    std::cout << "Execute Grade: " << tmp3.getExcGrade() << std::endl;

    std::cout << tmp1;
    std::cout << tmp2;
    std::cout << tmp3;

    Bureaucrat btmp1("btmp1", 5);
    tmp1.beSigned(btmp1);
    std::cout << "Signed: " << tmp1.getSigned() << std::endl;

}
