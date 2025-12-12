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

Cat::Cat(const Cat& other): Animal(other)
{
	this->type = other.type;
	std::cout << "A new cat is born" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->type = other.type;
	}
	return *this;
}

void Cat::makeSound()const
{
	std::cout << "Meow" << std::endl;
}
