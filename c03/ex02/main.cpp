#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "\n===== TEST 1: ClapTrap basic functionality =====\n";
    {
        ClapTrap ct("Basic");
        ct.attack("Enemy1");
        ct.takeDamage(5);
        ct.beRepaired(3);
        ct.attack("Enemy2");
    }

    std::cout << "\n===== TEST 2: ScavTrap functionality + Gate Keeper mode =====\n";
    {
        ScavTrap st("Guardian");
        st.attack("Intruder");
        st.takeDamage(20);
        st.beRepaired(10);
        st.guardGate();
    }

    std::cout << "\n===== TEST 3: FragTrap functionality + High Five =====\n";
    {
        FragTrap ft("HighFiver");
        ft.attack("BadGuy");
        ft.takeDamage(40);
        ft.beRepaired(20);
        ft.highFivesGuys();
    }

    std::cout << "\n===== TEST 4: Energy draining test =====\n";
    {
        ClapTrap ct("Exhausted");
        for (int i = 0; i < 12; i++)
            ct.attack("Dummy");
    }

    std::cout << "\n===== TEST 5: Hit point = 0 test =====\n";
    {
        ClapTrap ct("Dying");
        ct.takeDamage(10);
        ct.attack("Nobody");
        ct.beRepaired(5);
    }

    std::cout << "\n===== TEST END =====\n";

    return 0;
}
