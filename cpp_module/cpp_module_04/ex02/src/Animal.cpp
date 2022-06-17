#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal(" << this->type << ") - default onstructor has been called." << std::endl;
}

Animal::Animal(std::string type) : type(type) {
    std::cout << "Animal(" << this->type << ") - constructor has been called." << std::endl;
}

Animal::Animal(const Animal& obj) {
    std::cout << "Animal(" << this->type << ") - copy constructor has been called." << std::endl;
    *this = obj;
}

Animal::~Animal() {
    std::cout << "Animal(" << this->type << ") - destructor has been called." << std::endl;
}

Animal& Animal::operator=(const Animal& obj) {
    std::cout << "Animal(" << this->type << ") - operator= has been called." << std::endl;
    this->type = obj.type;
    return *this;
}

std::string Animal::getType() const {
    return this->type;
}
