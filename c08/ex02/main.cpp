#include "MutantStack.hpp"
#include <iostream>
#include <list>
void print(MutantStack<int>::const_iterator cit_b, MutantStack<int>::const_iterator cit_e)
{
    for (; cit_b != cit_e; cit_b++)
        std::cout << *cit_b << std::endl;
}


int main() {
    std::cout << "--- Subject Test with MutantStack ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it_b = mstack.begin();
    MutantStack<int>::iterator it_e = mstack.end();
    MutantStack<int>::const_iterator cit_e = mstack.end();
    MutantStack<int>::const_iterator cit_b = mstack.begin();
    ++it_b;
    --it_b;
    while (it_b != it_e)
    {
        *it_b = *it_b + 1;
        ++it_b;
    }
    print(cit_b, cit_e);
    std::cout << "\n--- Same Test with std::list ---" << std::endl;
    std::list<int> ls;
    ls.push_back(5);
    ls.push_back(17);
    std::cout << "back: " << ls.back() << std::endl;
    ls.pop_back();
    std::cout << "size: " << ls.size() << std::endl;
    ls.push_back(3);
    ls.push_back(5);
    ls.push_back(737);
    ls.push_back(0);
    std::list<int>::iterator lit = ls.begin();
    std::list<int>::iterator lite = ls.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    return 0;
}
