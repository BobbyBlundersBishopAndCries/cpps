#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>
int main()
{
    std::cout << "--- Vector Test ---" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 5; ++i)
        vec.push_back(i * 10);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Found: " << *it << std::endl;
        easyfind(vec, 42);
        
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "\n--- List Test ---" << std::endl;
    std::list<int> lst;
    for (int i = 0; i < 5; ++i)
        lst.push_back(i * 5);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 15);
        std::cout << "Found: " << *it << std::endl;
        easyfind(lst, 100); // Should throw
        
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
