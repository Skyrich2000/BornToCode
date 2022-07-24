#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    this->brain = new Brain();
    std::cout << "Cat - default onstructor has been called." << std::endl;
}

Cat::Cat(const Cat& obj) {
    this->brain = new Brain();
    std::cout << "Cat - copy constructor has been called." << std::endl;
    *this = obj;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat - destructor has been called." << std::endl;
}

Cat& Cat::operator=(const Cat& obj) {
    std::cout << "Cat - operator= has been called." << std::endl;
    if (this != &obj) {
        this->type = obj.type;
        *this->brain = *obj.brain;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Cat - Cat sound!" << std::endl;
}

Brain* Cat::getBrain() const {
    return this->brain;
}

void Cat::printBrain() const {
    this->brain->printIdeas();
}