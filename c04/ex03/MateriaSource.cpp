#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.templates[i] != NULL)
            templates[i] = other.templates[i]->clone();
        else
            templates[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (templates[i] != NULL)
            {
                delete templates[i];
                templates[i] = NULL;
            }

            if (other.templates[i] != NULL)
                templates[i] = other.templates[i]->clone();
            else
                templates[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] != NULL)
            delete templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m == NULL)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (templates[i] == NULL)
        {
            templates[i] = m->clone();
            delete m;
            return;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] != NULL)
        {
            if (templates[i]->getType() == type)
                return templates[i]->clone();
        }
    }
    return NULL;
}
