#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(int raw, bool) : number(raw) {}

Fixed::Fixed() : number(0) {}

Fixed::Fixed(const int value) {
    number = value << c;
}

Fixed::Fixed(const float value) {
    number = static_cast<int>(roundf(value * (1 << c)));
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        number = other.number;
    return *this;
}

int Fixed::getRawBits(void) const {
    return number;
}

void Fixed::setRawBits(int const raw) {
    number = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(number) / (1 << c);
}

int Fixed::toInt(void) const {
    return number >> c;
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed) {
    o << fixed.toFloat();
    return o;
}

bool Fixed::operator>(const Fixed& other) const { return number > other.number; }
bool Fixed::operator<(const Fixed& other) const { return number < other.number; }
bool Fixed::operator>=(const Fixed& other) const { return number >= other.number; }
bool Fixed::operator<=(const Fixed& other) const { return number <= other.number; }
bool Fixed::operator==(const Fixed& other) const { return number == other.number; }
bool Fixed::operator!=(const Fixed& other) const { return number != other.number; }

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(number + other.number, true);
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(number - other.number, true);
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed((number * other.number) >> c, true);
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed((number << c) / other.number, true);
}

Fixed& Fixed::operator++() {
    number++;
    return *this;
}

Fixed& Fixed::operator--() {
    number--;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    number++;
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    number--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a.number < b.number) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a.number < b.number) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a.number > b.number) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a.number > b.number) ? a : b;
}

