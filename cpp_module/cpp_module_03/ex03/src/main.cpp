#include <string>

#include "DiamondTrap.hpp"

int main() {
    DiamondTrap a("ycha");

    a.whoAmI();

    a.guardGate();
    a.highFivesGuys();
    a.beRepaired(10);

    a.attack("ucha");
}