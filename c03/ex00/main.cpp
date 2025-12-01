#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Bob");

    a.attack("target dummy");
    a.takeDamage(5);
    a.beRepaired(3);
    a.takeDamage(20);
    a.attack("something");

    return 0;
}
