#include "Zombie.hpp"
#include <iostream>
int main()
{
	Zombie a("hamid");
	Zombie *b = newZombie("heap goat");

	b->announce();
	a.announce();
	randomChump("hi");
	delete b;
	return 0;
}