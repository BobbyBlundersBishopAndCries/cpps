#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
            throw "Error";

        parse_args(argc, argv);
        run();
    }
    catch (const char *msg)
    {
        std::cerr << msg;
        return (1);
    }
    return (0);
}