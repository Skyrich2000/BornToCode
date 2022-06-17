#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog - default onstructor has been called." << std::endl;
}

Dog::Dog(const Dog& obj) {
    std::cout << "Dog - copy constructor has been called." << std::endl;
    *this = obj;
}

Dog::~Dog() {
    std::cout << "Dog - destructor has been called." << std::endl;
}

Dog& Dog::operator=(const Dog& obj) {
    std::cout << "Dog - operator= has been called." << std::endl;
    if (this != &obj) {
        this->type = obj.type;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Dog - Dog sound!" << std::endl;
}