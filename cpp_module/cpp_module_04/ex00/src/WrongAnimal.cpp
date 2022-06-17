#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal(" << this->type << ") - default onstructor has been called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
    std::cout << "WrongAnimal(" << this->type << ") - constructor has been called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) {
    std::cout << "WrongAnimal(" << this->type << ") - copy constructor has been called." << std::endl;
    *this = obj;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal(" << this->type << ") - destructor has been called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
    std::cout << "WrongAnimal(" << this->type << ") - operator= has been called." << std::endl;
    this->type = obj.type;
    return *this;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal(" << this->type << ") - Wrong Aniaml sound!" << std::endl;
}
