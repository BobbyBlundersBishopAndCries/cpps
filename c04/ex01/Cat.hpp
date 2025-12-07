#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain *brain;

public:
    Cat();
    Cat(const Cat& other);             // <-- ADD THIS
    Cat& operator=(const Cat& other);  // <-- ADD THIS
    ~Cat();

    void makeSound(void) const;
};

#endif
