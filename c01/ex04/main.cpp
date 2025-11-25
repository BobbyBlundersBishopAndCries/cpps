#include <iostream>
#include "Sed.hpp"

int main(int ac, char **av)
{
	if (ac != 4) {
		std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	Sed sed(av[1], av[2], av[3]);
	sed.Replace();

	return 0;
}
