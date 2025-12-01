#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>

class ClapTrap{
	private:
		std::string		name;
		unsigned int	hit_pts;
		unsigned int	energy_pts;
		unsigned int	attack_dmg;
	public:
		ClapTrap(const std::string name);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	    void setName(const std::string& n);
    	void setHP(unsigned int v);
    	void setEP(unsigned int v);
    	void setAD(unsigned int v);
    	const std::string& getName() const;
    	unsigned int getHP() const;
    	unsigned int getEP() const;
    	unsigned int getAD() const;
};
#endif