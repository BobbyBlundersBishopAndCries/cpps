#include "Fixed.hpp"
#include <iostream>

int main(void) {
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;
	
    std::cout << a.getRawBits() << std::endl;  // 0
    std::cout << b.getRawBits() << std::endl;  // 0
    std::cout << c.getRawBits() << std::endl;  // 0
    return 0;
}
