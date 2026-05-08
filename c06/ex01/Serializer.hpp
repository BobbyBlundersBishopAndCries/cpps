#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data {
    int data_int;
    std::string data_name;
    float data_float;
};

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer& a);
        Serializer operator=(Serializer& a);
        ~Serializer();
    public:
        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);
};
#endif