#include "Cat.hpp"

Cat::Cat():Animal()
{
	type = "Cat";
	std::cout << "A new cat is born" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Poor cat died" << std::endl;
}

void Cat::makeSound()const
{
	std::cout << "Meow" << std::endl;
}
