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
    uintptr_t serialized = Serializer::serialize(tmp);

    Data *deserialized = Serializer::deserialize(serialized);
    std::cout << deserialized->tmp3 << std::endl;

    delete tmp;
}
