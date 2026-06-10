#include "MutantStack.hpp"
#include <iostream>
#include <list>
void print(MutantStack<int>::const_iterator& cit_b, MutantStack<int>::const_iterator& cit_e)
{
    MutantStack<int>::const_iterator temp =  cit_b;
    std::cout << " ---Printing forward iterator---\n";
    for (; temp != cit_e; temp++)
        std::cout << *temp << std::endl;
}

void print_rev(MutantStack<int>::const_reverse_iterator& crit_b, MutantStack<int>::const_reverse_iterator& crit_e)
{
    MutantStack<int>::const_reverse_iterator temp =  crit_b;
    std::cout << " ---Reverse iterator---\n";
    for (; temp != crit_e; temp++)
        std::cout << *temp << std::endl;
    
}
void swap_order(MutantStack<int>::reverse_iterator& rit_b, MutantStack<int>::reverse_iterator rit_e)
{
    while (rit_b != rit_e)
    {
        int tmp = *rit_b;
        *rit_b = *rit_e;
        *rit_e = tmp;
        ++rit_b;
        if (rit_b == rit_e)
            break;
        --rit_e;
        if (rit_b == rit_e)
            break;
    }
}
// overloadig with list now
void print(std::list<int>::const_iterator& cit_b, std::list<int>::const_iterator& cit_e)
{
    std::list<int>::const_iterator temp = cit_b;
    std::cout << " ---Printing forward iterator---\n";
    for (; temp != cit_e; ++temp)
        std::cout << *temp << std::endl;
}

void print_rev(std::list<int>::const_reverse_iterator& crit_b, std::list<int>::const_reverse_iterator& crit_e)
{
    std::list<int>::const_reverse_iterator temp = crit_b;
    std::cout << " ---Reverse iterator---\n";
    for (; temp != crit_e; ++temp)
        std::cout << *temp << std::endl;
}

void swap_order(std::list<int>::reverse_iterator &rit_b,std::list<int>::reverse_iterator &rit_e)
{
    while (rit_b != rit_e)
    {
        int tmp = *rit_b;
        *rit_b = *rit_e;
        *rit_e = tmp;
        ++rit_b;
        if (rit_b == rit_e)
            break;
        --rit_e;
        if (rit_b == rit_e)
            break;
    }
}

int main() {
    std::cout << "--- Subject Test with MutantStack ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(0);
    mstack.push(1);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);
    std::cout << "size: " << mstack.size() << std::endl;
    MutantStack<int>::iterator it_b = mstack.begin();
    MutantStack<int>::iterator it_e = mstack.end();
    MutantStack<int>::const_iterator cit_b = mstack.begin();
    MutantStack<int>::const_iterator cit_e = mstack.end();
    MutantStack<int>::reverse_iterator rit_b = mstack.rbegin();
    MutantStack<int>::reverse_iterator rit_e = mstack.rend() - 1;
    MutantStack<int>::const_reverse_iterator crit_b = mstack.rbegin() + 1; //skipp last el
    MutantStack<int>::const_reverse_iterator crit_e = mstack.rend();

    ++it_b;
    --it_b;
    while (it_b != it_e)
    {
        *it_b = *it_b + 1;
        ++it_b;
    }

    print(cit_b,cit_e);//1 3 4 5 6
    print_rev(crit_b,crit_e);// 5 4 3 1 in this order
    swap_order(rit_b,rit_e);
    print(cit_b,cit_e); // should print 6 5 4 3 1 (1 3 4 5 6 the swapped one)

    std::cout << "\n--- Same Test with std::list ---\n";
    std::list<int> ls;
    ls.push_back(0);
    ls.push_back(1);
    std::cout << "back: " << ls.back() << std::endl;
    ls.pop_back();
    ls.push_back(2);
    ls.push_back(3);
    ls.push_back(4);
    ls.push_back(5);
    std::cout << "size: " << ls.size() << std::endl;
    std::list<int>::iterator itb = ls.begin();
    std::list<int>::iterator ite = ls.end();
    std::list<int>::const_iterator citb = ls.begin();
    std::list<int>::const_iterator cite = ls.end();
    std::list<int>::reverse_iterator ritb = ls.rbegin();
    std::list<int>::reverse_iterator rite = ls.rend();
    rite--;//point to the first element
    std::list<int>::const_reverse_iterator critb = ls.rbegin();
    critb++;//skip last ele
    std::list<int>::const_reverse_iterator crite = ls.rend();
    ++itb;
    --itb;
    while (itb != ite)
    {
        *itb += 1;
        ++itb;
    }
    print(citb, cite);      // 1 3 4 5 6
    print_rev(critb, crite); // 5 4 3 1
    swap_order(ritb,rite);
    print(citb, cite);      // 6 5 4 3 1
    return 0;
}
