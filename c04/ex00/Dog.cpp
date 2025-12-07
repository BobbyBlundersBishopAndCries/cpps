#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
    type = "Dog";
    std::cout << "A new Dog is born!" << std::endl;
}

Dog::~Dog() {
    std::cout << "Poor Dog died!" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}
