#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : number(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : number(value << Fixed::c) {
    std::cout << "Int constructor called" << std::endl;
} 
Fixed::Fixed(const float value) : number(static_cast<int>(roundf(value * (1 << Fixed::c)))) {
    std::cout << "Float constructor called" << std::endl;
}
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed& original) : number(original.number) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& original) {
    if (this != &original) {
        number = original.number;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return number;
}

void Fixed::setRawBits(int const raw) {
    number = raw;
}

float Fixed::toFloat(void) const {
    return number / 256.0f;
}

int Fixed::toInt(void) const {
    return number >> Fixed::c;
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed) {
    o << fixed.toFloat();
    return o;
}
