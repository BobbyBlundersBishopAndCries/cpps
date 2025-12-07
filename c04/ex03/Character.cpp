#include "Character.hpp"

Character::Character(){}
Character::Character(const std::string & name):name(name)
{
	for(int i = 0; i < 4; i++)
		this->slots[i] = NULL;
}
Character::Character(const Character& other) : name(other.name)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.slots[i] != NULL)
            slots[i] = other.slots[i]->clone();
        else
            slots[i] = NULL;
    }
}
Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        name = other.name;
        _deleteInventory();

        for (int i = 0; i < 4; ++i)
        {
            if (other.slots[i] != NULL)
                slots[i] = other.slots[i]->clone();
            else
                slots[i] = NULL;
        }
    }
    return *this;
}
void Character::_deleteInventory()
{
    for (int i = 0; i < 4; ++i)
    {
        if (slots[i])
        {
            delete slots[i];
            slots[i] = NULL;
        }
    }
}
Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (slots[i] != NULL)
            delete slots[i];
    }
}
std::string const & Character::getName() const
{
    return name;
}
void Character::equip(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (slots[i] == NULL)
        {
            slots[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;
    slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
        return;
    if (slots[idx] != NULL)
        slots[idx]->use(target);
}
