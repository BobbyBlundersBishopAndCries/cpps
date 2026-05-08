#include "Serializer.hpp"

int main()
{
    Data myData;
    myData.data_int = 42;
    myData.data_name = "Forty-Two";
    myData.data_float = 42.42f;

    std::cout << "--- ORIGINAL DATA ---" << std::endl;
    std::cout << "Address: " << &myData << std::endl;
    std::cout << "Int:     " << myData.data_int << std::endl;
    std::cout << "Name:    " << myData.data_name << std::endl;
    std::cout << "Float:   " << myData.data_float << std::endl;
    std::cout << "---------------------\n" << std::endl;

    uintptr_t serializedPtr = Serializer::serialize(&myData);
    std::cout << "Serialized uintptr_t: " << serializedPtr << "\n" << std::endl;
    Data *deserializedData = Serializer::deserialize(serializedPtr);

    std::cout << "--- DESERIALIZED DATA ---" << std::endl;
    std::cout << "Address: " << deserializedData << std::endl;
    std::cout << "Int:     " << deserializedData->data_int << std::endl;
    std::cout << "Name:    " << deserializedData->data_name << std::endl;
    std::cout << "Float:   " << deserializedData->data_float << std::endl;
    std::cout << "-------------------------\n" << std::endl;
    if (&myData == deserializedData) {
        std::cout << "SUCCESS: Pointers are equal! Reinterpret cast worked perfectly." << std::endl;
    } else {
        std::cout << "ERROR: Pointers do not match." << std::endl;
    }

    return 0;
}