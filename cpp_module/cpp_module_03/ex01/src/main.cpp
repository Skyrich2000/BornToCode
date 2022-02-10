#include <string>

#include "ScavTrap.hpp"

int main() {
    ScavTrap a("a");
    ScavTrap b("b");
    ScavTrap c;

    c = a;

    a.attack("b");
    b.takeDamage(0);

    b.beRepaired(10);
    a.guardGate();
}