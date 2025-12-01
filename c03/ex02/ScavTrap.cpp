#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string& n) : ClapTrap(n)
{
    setHP(100);
    setEP(50);
    setAD(20);

    std::cout << "ScavTrap " << getName() << " constructed!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << getName() << " destroyed!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is now in Gate Keeper mode!" << std::endl;
}
