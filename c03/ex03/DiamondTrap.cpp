#include "DiamondTrap.hpp"
#include  <iostream>
DiamondTrap::DiamondTrap(const std::string& newname)
    : ClapTrap(newname + "_clap_name"),ScavTrap(newname) ,FragTrap(newname) ,name(newname)
{
    setHP(FragTrap::getHP());
    setEP(ScavTrap::getEP());
    setAD(FragTrap::getAD());

    std::cout << "DiamondTrap " << name << " constructed!" << std::endl;
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " destroyed!" << std::endl;
}
void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << name
              << ", ClapTrap name: " << ClapTrap::getName() << std::endl;
}
