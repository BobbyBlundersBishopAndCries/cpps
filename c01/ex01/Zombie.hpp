#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include<string>
class Zombie{
	private:
		std::string name;

	public:
		Zombie(std::string name);
		Zombie();
		~Zombie();
		void announce(void);
		void setName(const std::string &n); 
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
Zombie* zombieHorde(int N, std::string name);
#endif