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
	int N;
	std:: string nameIt;
	std::cout << "enter the number of zombies you want your glorious horde to hold :";
	std::cin >> N;
	std::cin.ignore();
	std::cout << "give your horde a glorious name as yours:";
	std::getline(std::cin ,nameIt);
	Zombie *horde = zombieHorde(N,nameIt);
	for (int i = 0; i < N; i++)
        horde[i].announce();
	delete [] horde;
	return 0;
}