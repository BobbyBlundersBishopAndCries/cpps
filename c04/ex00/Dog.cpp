#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
    type = "Dog";
    std::cout << "A new Dog is born!" << std::endl;
}

Dog::~Dog() {
    std::cout << "Poor Dog died!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    this->type = other.type;
    std::cout << "A new Dog is born!" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        this->type = other.type;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}
