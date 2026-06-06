#include "Span.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Subject Test ---" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "\n--- Large Span Test ---" << std::endl;
    Span largeSp(10000);
    std::vector<int> vec;
    for (int i = 0; i < 10000; ++i)
        vec.push_back(i * 2);
    largeSp.addNumber(vec.begin(), vec.end());
    std::cout << largeSp.shortestSpan() << std::endl;
    std::cout << largeSp.longestSpan() << std::endl;
    
    std::cout << "\n--- Exceptions Test ---" << std::endl;
    try
    {
        Span emptySpan(2);
        emptySpan.addNumber(1);
        emptySpan.shortestSpan();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Span fullSpan(1);
        fullSpan.addNumber(1);
        fullSpan.addNumber(2);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
