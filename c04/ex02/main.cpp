#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
const Animal* i = new Cat();
delete i;
return 0;
}