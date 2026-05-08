#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << "--- Testing dynamic_cast with Random Objects ---" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "\n[ Test " << i + 1 << " ]" << std::endl;
        Base* randomObject = generate();
        std::cout << "Pointer identify   : ";
        identify(randomObject);
        
        std::cout << "Reference identify : ";
        identify(*randomObject);
        delete randomObject;
    }
    std::cout << "\n--- Testing Complete ---" << std::endl;
    return 0;
}