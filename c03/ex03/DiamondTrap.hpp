#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
class DiamondTrap : public ScavTrap, public FragTrap
{
	std::string name;
public:
	DiamondTrap(const std::string &name);
	~DiamondTrap();
	void whoAmI();
	using ScavTrap::attack;
};

#endif