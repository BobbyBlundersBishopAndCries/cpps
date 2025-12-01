#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "\n--- Testing ClapTrap ---\n" << std::endl;

    ClapTrap c1("Alpha");
    c1.attack("Target1");
    c1.takeDamage(5);
    c1.beRepaired(3);
    c1.takeDamage(20);
    c1.attack("Target2");
    c1.beRepaired(10);

    std::cout << "\n--- Testing ScavTrap ---\n" << std::endl;

    ScavTrap s1("Guardian");
    s1.attack("Enemy1");
    s1.takeDamage(30);
    s1.beRepaired(20);
    s1.guardGate();

    std::cout << "\n--- Energy draining test ---\n" << std::endl;
    for (int i = 0; i < 55; i++) {
        s1.attack("EnemyX");
    }

    std::cout << "\n--- Multiple instances test ---\n" << std::endl;
    ClapTrap c2("Beta");
    ScavTrap s2("Sentinel");

    c2.attack("Dummy");
    s2.guardGate();
    s2.takeDamage(50);
    s2.beRepaired(10);
    s2.attack("Dummy2");

    std::cout << "\n--- End of tests ---\n" << std::endl;

    return 0;
}
