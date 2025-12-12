#include "Animal.hpp"

Animal::Animal():type("Animal")
{
	std::cout << "A new animal is born" << std::endl;
}

Animal::Animal(const Animal& other): type(other.type)
{
	std::cout << "A new animal is born" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Poor animal died" << std::endl;
}

void Animal::makeSound(void)const
{
	std::cout << "making an animal sound" << std::endl;
}

std::string Animal::getType()const
{
	return this->type;
}