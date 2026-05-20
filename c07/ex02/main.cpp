#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    std::cout << "--- Testing Default Constructor ---" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    try {
        emptyArray[0] = 42;
    } catch (std::exception& e) {
        std::cout << "Exception caught (empty array): " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing Constructor with size ---" << std::endl;
    Array<int> iArray(5);
    std::cout << "Int array size: " << iArray.size() << std::endl;
    for (unsigned int i = 0; i < iArray.size(); ++i) {
        std::cout << "iArray[" << i << "] = " << iArray[i] << " (default init)" << std::endl;
        iArray[i] = i * 10;
    }

    std::cout << "\n--- Testing Copy Constructor & Deep Copy ---" << std::endl;
    Array<int> copyArray(iArray);
    std::cout << "Copy array[2]: " << copyArray[2] << std::endl;
    copyArray[2] = 999;
    std::cout << "Modifying copy... copy array[2] = " << copyArray[2] << std::endl;
    std::cout << "Original array stays same... iArray[2] = " << iArray[2] << std::endl;

    std::cout << "\n--- Testing String Array ---" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "C++";
    strArray[2] = "Templates!";
    for (unsigned int i = 0; i < strArray.size(); ++i) {
        std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
    }

    std::cout << "\n--- Testing Out of Bounds Exception ---" << std::endl;
    try {
        strArray[3] = "Out of Bounds";
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
