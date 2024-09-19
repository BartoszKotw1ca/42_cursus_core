#pragma once
#include <iostream>
#include "Data.cpp"
// #include <cstdint>
#include <stdint.h>

class Serializer
{
    public:
        ~Serializer( void );
        Serializer (const Serializer & other);
        Serializer & operator=( const Serializer & other);

        // static uintptr_t serialize(Data* ptr);
        static Data*  deserialize(uintptr_t raw);

    private:
        Serializer( void );
} ;
