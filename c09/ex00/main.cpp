#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr<< "Error: could not open file\n";
        return 1;
    }
    init_map();
    return read_file(av[1]);
}