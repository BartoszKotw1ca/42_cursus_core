#include "Serializer.hpp"

Serializer :: Serializer ( void )
{
    std::cout << "Serializer constructor!" << std::endl;
}

Serializer :: ~Serializer ( void )
{
    std::cout << "Serializer destructor!" << std::endl;
}

Serializer & Serializer :: operator= ( const Serializer & other)
{
   (void ) other;
   return *this;
}

Serializer :: Serializer ( const Serializer & other)
{
    (void ) other;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data * Serializer :: deserialize ( uintptr_t raw )
{
    return reinterpret_cast<Data*>(raw);
}
