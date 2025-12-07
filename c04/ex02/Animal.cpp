#include "Animal.hpp"

Animal::Animal():type("Animal")
{
	std::cout << "A new animal is born" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Poor animal died" << std::endl;
}

std::string Animal::getType()const
{
	return this->type;
}