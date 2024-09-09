#include "Bureaucrat.hpp"

int main ( void )
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
