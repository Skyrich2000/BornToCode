#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

void HumanB::attack() {
    std::cout << this->name << " attacks with their ";
    if (this->weapon)
        std::cout << this->weapon->getType();
    else
        std::cout << "nothing";
    std::cout << std::endl;
}