#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Icharacter.hpp"
#include "AMateria.hpp"
#include <string>
class Character: public ICharacter
{
	private:
		AMateria* slots[4];
		std::string name;
		void _deleteInventory();
	public:
		Character();
		Character(const std::string& name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		virtual ~Character();
		virtual std::string const & getName() const;
    	virtual void equip(AMateria* m);
    	virtual void unequip(int idx);
    	virtual void use(int idx, ICharacter& target);

};
#endif