#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
    type = "Dog";
    brain = new Brain();
    std::cout << "A new Dog is born!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor" << std::endl;
    brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator" << std::endl;
    if (this != &other) {
        type = other.type;
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Poor Dog died!" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}
