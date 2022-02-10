#include <string>

#include "ClapTrap.hpp"

int main() {
    ClapTrap a("a");
    ClapTrap b("b");

    a.attack("b");
    b.takeDamage(0);

    b.beRepaired(10);
}