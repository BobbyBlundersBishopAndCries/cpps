#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string n)
    : name(n), hit_pts(10), energy_pts(10), attack_dmg(0)
{
    std::cout << "ClapTrap " << name << " created!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (hit_pts == 0) {
        std::cout << "ClapTrap " << name << " cannot attack, it is dead!" << std::endl;
        return;
    }
    if (energy_pts == 0) {
        std::cout << "ClapTrap " << name << " has no energy left to attack!" << std::endl;
        return;
    }
    energy_pts--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_dmg << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hit_pts == 0) {
        std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
        return;
    }

    if (amount >= hit_pts)
        hit_pts = 0;
    else
        hit_pts -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining HP: " << hit_pts << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hit_pts == 0) {
        std::cout << "ClapTrap " << name << " cannot repair, it is dead!" << std::endl;
        return;
    }
    if (energy_pts == 0) {
        std::cout << "ClapTrap " << name << " has no energy left to repair!" << std::endl;
        return;
    }

    energy_pts--;
    hit_pts += amount;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points! New HP: " << hit_pts << std::endl;
}
