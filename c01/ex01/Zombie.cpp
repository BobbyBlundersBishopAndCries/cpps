#include "Zombie.hpp"
#include <iostream>
Zombie::Zombie(std::string name):name(name){};
Zombie::~Zombie()
{
	std::cout<< name << std::endl;
}
void Zombie::announce(void)
{
	std::cout<< name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie* newZombie( std::string name )
{
	return new Zombie(name);
}
void	randomChump(std::string name)
{
	Zombie a(name);
	a.announce();
}
void Zombie::setName(const std::string &n)
{
	name = n;
}