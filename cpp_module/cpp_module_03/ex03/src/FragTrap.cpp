#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
    this->hit = 100;
    this->energy = 100;
    this->damage = 30;
    std::cout << "FragTrap [" << this->name << "] - default constructor has been called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->hit = 100;
    this->energy = 100;
    this->damage = 30;
    std::cout << "FragTrap [" << this->name << "] - name constructor has been called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj) {
    std::cout << "FragTrap [" << this->name << "] - copy constructor has been called." << std::endl;
    *this = obj;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap [" << this->name << "] - destructor has been called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj) {
    std::cout << "FragTrap [" << this->name << "] - operator= has been called." << std::endl;
    this->name = obj.name;
    this->hit = obj.hit;
    this->energy = obj.energy;
    this->damage = obj.damage;
    return *this;
}

void FragTrap::attack(const std::string& target) {
    std::cout << "FragTrap [" << this->name << "] - attack " << target << ", causing " << this->damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap [" << this->name << "] - a positive high fives request" << std::endl;
}