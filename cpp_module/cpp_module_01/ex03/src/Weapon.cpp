#include "Weapon.hpp"

Weapon::Weapon(const char *type) : type(type) {}

Weapon::~Weapon() {}

std::string Weapon::getType() const {
    return this->type;
}

void Weapon::setType(const char *type) {
    this->type = type;
}