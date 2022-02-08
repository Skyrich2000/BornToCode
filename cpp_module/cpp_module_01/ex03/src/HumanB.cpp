#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(const char *name) : name(name), weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

void HumanB::attack() {
    std::cout << this->name << " use ";
    if (this->weapon)
        std::cout << this->weapon->getType();
    else
        std::cout << "nothing";
    std::cout << std::endl;
}