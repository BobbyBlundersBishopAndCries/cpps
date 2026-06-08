#pragma once
#include <exception>


class NotFoundException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Value not found in container.";
        }
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it;
    for(it = container.begin(); it != container.end(); ++it)
    {
        if(*it == value)
            return it;
    }
    if (it == container.end())
        throw NotFoundException();
    return it;
}
