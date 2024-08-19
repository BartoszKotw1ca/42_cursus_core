#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal(std::string type = "Animal");
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal &operator=(const WrongAnimal &other);
        virtual ~WrongAnimal(void);

        void makeSound(void) const;
        std::string getType(void) const;

    protected:
        std::string _type;
};

#endif
