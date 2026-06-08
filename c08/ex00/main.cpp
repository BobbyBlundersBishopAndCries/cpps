#include "easyfind.hpp"
#include <deque>
#include <iterator>
#include <vector>
#include <list>
// #include <array>
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
        std::vector<int>::iterator exc = easyfind(vec, 42);
        std::cout << "Found: " << *exc << std::endl;
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
    try
    {
        std::vector<int> a(5,2);
        for (size_t i = 0; i < a.size(); i++)
            std::cout << "a["<< i << "] = "<<a[i] << std::endl;
        std::vector<int>::iterator it = easyfind(a,2);
        size_t x = std::distance(a.begin(), it);
        /* First occurence check */
        std::cout << "first occurence (should be 0 first index) = " << x << std::endl;
        std::cout << "  --- Exception test ---\n";
        easyfind(a,5);
    }
    catch(std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "\n--- Deque Test ---" << std::endl;
    try
    {
        std::deque<int> dq;
        for (size_t i = 0; i < 5; i++)
        {
            dq.push_back(100 + i);
            dq.push_front(100 + 4 - i);
        }
        for (size_t i = 0; i < dq.size(); i++)
        {
            if(i == 0)
                std::cout << "\" ";
            std::cout << dq[i];
            if (i!= dq.size() - 1)
                std::cout <<  " "; 
            if(i == dq.size() - 1)
                std::cout << "\"" << std::endl;
        }
        std::deque<int>::iterator it = easyfind(dq, 101);
        std::cout << "This should print and iterator value is = " <<* it << "\nIndex is = "<< std::distance(dq.begin(),it) <<  std::endl;
        easyfind(dq, 18);
                std::cout << "This should never print" << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    // std::cout << "\n--- Array Test ---" << std::endl;
    /*another test but std::array was introduced in C++11*/
    // std::array<int,10> arr;
    // for (int i = 0; i < 10; i++)
    //     arr[i] = i * 2;
    // try
    // {
    //     std::array<int,10>::iterator it = easyfind(arr, 18);
    //     std::cout << "Found: " << *it << std::endl;
    //     std::array<int,10>::iterator exc = easyfind(arr, 42);
    //     std::cout << "Found: " << *exc << std::endl;
    // }
    // catch (std::exception& e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    return 0;
}
