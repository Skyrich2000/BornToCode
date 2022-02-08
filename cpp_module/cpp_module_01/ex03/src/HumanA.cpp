#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(const char *name, Weapon &weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() {
    std::cout << this->name << " use " << this->weapon.getType() << std::endl;
}