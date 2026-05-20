#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(const T& element) {
    std::cout << element << std::endl;
}

template <typename T>
void incrementElement(T& element) {
    ++element;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArray) / sizeof(int);

    std::cout << "Original intArray:" << std::endl;
    ::iter(intArray, intLen, printElement<int>);

    ::iter(intArray, intLen, incrementElement<int>);

    std::cout << "After incrementing intArray:" << std::endl;
    ::iter(intArray, intLen, printElement<int>);

    std::string strArray[] = {"Hello", "World", "C++", "Templates"};
    size_t strLen = sizeof(strArray) / sizeof(std::string);

    std::cout << "\nString Array:" << std::endl;
    ::iter(strArray, strLen, printElement<std::string>);

    return 0;
}
