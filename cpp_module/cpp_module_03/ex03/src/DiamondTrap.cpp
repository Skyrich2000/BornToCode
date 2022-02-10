#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap(), ClapTrap(), name("noname") {
    std::cout << "DiamondTrap [" << this->name << "] - default onstructor has been called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name : ScavTrap(name), {
    std::cout << "DiamondTrap [" << this->name << "] - default onstructor has been called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) {
    std::cout << "DiamondTrap [" << this->name << "] - copy constructor has been called." << std::endl;
    *this = obj;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap [" << this->name << "] - destructor has been called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
    std::cout << "DiamondTrap [" << this->name << "] - operator= has been called." << std::endl;
    // this->name = obj.name;
    // Fragtrap::hit = obj.hit;
    // this->energy = obj.energy;
    // this->damage = obj.damage;
    return *this;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {

}