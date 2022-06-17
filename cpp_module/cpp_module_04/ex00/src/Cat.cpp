#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat - default onstructor has been called." << std::endl;
}

Cat::Cat(const Cat& obj) {
    std::cout << "Cat - copy constructor has been called." << std::endl;
    *this = obj;
}

Cat::~Cat() {
    std::cout << "Cat - destructor has been called." << std::endl;
}

Cat& Cat::operator=(const Cat& obj) {
    std::cout << "Cat - operator= has been called." << std::endl;
    if (this != &obj) {
        this->type = obj.type;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Cat - Cat sound!" << std::endl;
}