#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

void HumanB::setWeapon(Weapon &new_weapon) {
    weapon = &new_weapon;
}

void HumanB::attack() const {
    if (weapon)
        std::cout << name << " attacks with their "
                  << weapon->getType() << std::endl;
    else
        std::cout << name << " is unarmed" << std::endl;
}
