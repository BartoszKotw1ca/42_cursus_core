// #include "Serializer.hpp"

// int main(void)
// {
//     // Serializer tmp();
//     Data *tmp = new Data;
//     // std::cout << tmp.tmp1 << std::endl;

//     tmp = Serializer::deserialize ( 90 );
//     std::cout << Serializer::deserialize( 90 ) << std::endl;
//     std::cout << tmp->tmp3 << std::endl;



// }

#include "Serializer.hpp"

int main(void)
{
    Data *tmp = new Data;
    uintptr_t   serialized;

    std::cout << "Adress tmp: "<< tmp << std::endl;
    serialized = Serializer::serialize(tmp);
    std::cout << "Serialized: " << serialized << std::endl;

    Data *deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized: " << deserialized << std::endl;

    delete tmp;
}
