#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap() : name("noname"), hit(10), energy(10), damage(0) {
    std::cout << "ClapTrap [" << this->name << "] - default onstructor has been called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit(10), energy(10), damage(0) {
    std::cout << "ClapTrap [" << this->name << "] - default onstructor has been called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) {
    std::cout << "ClapTrap [" << this->name << "] - copy constructor has been called." << std::endl;
    *this = obj;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap [" << this->name << "] - destructor has been called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
    std::cout << "ClapTrap [" << this->name << "] - operator= has been called." << std::endl;
    this->name = obj.name;
    this->hit = obj.hit;
    this->energy = obj.energy;
    this->damage = obj.damage;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    std::cout << "ClapTrap [" << this->name << "] - attack " << target << ", causing " << this->damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amout) {
    this->energy -= amout;
    std::cout << "ClapTrap [" << this->name << "] - takes " << amout << " damage and has " << this->energy << " energy." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amout) {
    this->energy += amout;
    std::cout << "ClapTrap [" << this->name << "] - repaired " << amout << " and has " << this->energy << " energy." << std::endl;
}
