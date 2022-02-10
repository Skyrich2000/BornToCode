#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
    this->hit = 100;
    this->energy = 50;
    this->damage = 20;
    std::cout << "ScavTrap [" << this->name << "] - default onstructor has been called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->hit = 100;
    this->energy = 50;
    this->damage = 20;
    std::cout << "ScavTrap [" << this->name << "] - default onstructor has been called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj) {
    std::cout << "ScavTrap [" << this->name << "] - copy constructor has been called." << std::endl;
    *this = obj;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap [" << this->name << "] - destructor has been called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
    std::cout << "ScavTrap [" << this->name << "] - operator= has been called." << std::endl;
    this->name = obj.name;
    this->hit = obj.hit;
    this->energy = obj.energy;
    this->damage = obj.damage;
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    std::cout << "ScavTrap [" << this->name << "] - attack " << target << ", causing " << this->damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap [" << this->name << "] - have enterred in Gate keeper mode. " << std::endl;
}