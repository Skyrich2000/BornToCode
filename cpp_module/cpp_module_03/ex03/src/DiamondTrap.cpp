#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("noname_clap_name"), ScavTrap(), FragTrap(), name("noname") {
    this->hit = 100;
    this->energy = 50;
    this->damage = 30;
    std::cout << "DiamondTrap [" << this->name << "] - default constructor has been called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) {
    this->hit = 100;
    this->energy = 50;
    this->damage = 30;
    std::cout << "DiamondTrap [" << this->name << "] - name constructor has been called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj) {
    std::cout << "DiamondTrap [" << this->name << "] - copy constructor has been called." << std::endl;
    *this = obj;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap [" << this->name << "] - destructor has been called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
    std::cout << "DiamondTrap [" << this->name << "] - operator= has been called." << std::endl;
    this->name = obj.name;
    this->hit = obj.hit;
    this->energy = obj.energy;
    this->damage = obj.damage;
    return *this;
}

void DiamondTrap::attack(const std::string& target) {
    this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap [" << this->name << "] - Claptrap name : " << this->ClapTrap::name << std::endl;
}