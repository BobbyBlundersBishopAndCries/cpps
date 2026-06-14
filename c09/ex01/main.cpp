#include "RPN.hpp"
int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "Usage: ./RPN <expression>\n";
        return 1;
    }
    int i;
    try
    {
        i = rpn(av[1]);
        std::cout << calc.top() << std::endl;
    }
    catch(const char *s)
    {
        std::cerr << s << std::endl;
    }
    return i;
}