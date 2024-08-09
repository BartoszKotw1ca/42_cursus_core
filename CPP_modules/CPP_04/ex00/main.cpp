#include "Animals.h"

// w tym przypadku nie uzywam 'virtual'
// co powoduje ze nie wywola sie metoda makeSound
//z klasy pochodnej
// tylko z klasy bazowej
void    wrong_animals( void )
{
    std::cout << "---Test for wrong classes---" << std::endl;
    const WrongAnimal *meta = new WrongAnimal();
    const WrongAnimal *i = new WrongCat();
    // std::cout << meta->getType() << std::endl;
    // std::cout << i->getType() << std::endl;
    i->makeSound();
    delete i;
    delete meta;
}

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    wrong_animals();
    return 0;
}