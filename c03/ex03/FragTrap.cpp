#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string &newname):ClapTrap(newname)
{
	setHP(100);
    setEP(100);
    setAD(30);

    std::cout << "FragTrap " << getName() << " constructed!" << std::endl;
}
FragTrap::~FragTrap() {
    std::cout << "FragTrap " << getName() << " destroyed!" << std::endl;
}
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << getName() << " requests a positive high five!" << std::endl;
}