#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./harlFilter <level>" << std::endl;
        return 1;
    }

    std::string level = argv[1];
    Harl harl;

    int lvl = -1;
    if (level == "DEBUG") lvl = 0;
    else if (level == "INFO") lvl = 1;
    else if (level == "WARNING") lvl = 2;
    else if (level == "ERROR") lvl = 3;

    switch (lvl)
    {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO");
        case 2:
            harl.complain("WARNING");
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }	

    return 0;
}
