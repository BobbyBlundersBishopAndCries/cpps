#include "DiamondTrap.hpp"
#include <iostream>
int main() {
    DiamondTrap dt("Diamond");

    dt.attack("Enemy");
    dt.beRepaired(20);
    dt.takeDamage(30);
    dt.whoAmI();

    std::cout << "End of test." << std::endl;
    return 0;
}
