#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
    type = "Cat";
    brain = new Brain();
    std::cout << "A new cat is born" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor" << std::endl;
    brain = new Brain(*other.brain); // deep copy
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator" << std::endl;
    if (this != &other) {
        type = other.type;
        delete brain;
        brain = new Brain(*other.brain); // deep copy
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Poor cat died" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}
