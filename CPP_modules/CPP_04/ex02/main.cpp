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

void    test_brain_animals( void )
{
    const int   numAnimals = 100;
    Animal *animals[numAnimals];

    for (int i = 0; i < numAnimals / 2; ++ i)
        animals[i] = new Dog();
    for (int i = numAnimals / 2; i < numAnimals; ++ i)
        animals[i] = new Cat();
    // animals[0]->makeSound();
    for (int i = 0; i < numAnimals; i ++)
        delete animals[i];
}

void    test_for_animal( void )
{
    // w tym przypadku nie moze uzyc tej klasy samej
    // poniewaz jest ona abstrakcyjna oznacza to
    // ze nie mozemy jej samej w sobie zaincjalizowac
    // mozemy miec taki typ jedynie jako wskaznik
    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    // std::cout << meta->getType() << std::endl; // This line should be removed
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    // meta->makeSound(); // This line should be removed
    // delete meta; // This line should be removed
    delete j;
    delete i;
}
int main()
{
    // test_for_animal();
    // wrong_animals();
    // test_brain_animals();

    return 0;
}
