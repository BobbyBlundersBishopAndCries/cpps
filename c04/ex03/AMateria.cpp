#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(const std::string &type):type(type)
{
}
std::string const & AMateria::getType() const
{
	return this->type;
}
AMateria::AMateria(AMateria const & other) : type(other.type) {}
AMateria & AMateria::operator=(AMateria const & other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}
void AMateria::use(ICharacter& target)
{
	(void)target;
}
AMateria::~AMateria(){}

