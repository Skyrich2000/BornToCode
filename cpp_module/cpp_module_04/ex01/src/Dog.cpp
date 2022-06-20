#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    this->brain = new Brain();
    std::cout << "Dog - default onstructor has been called." << std::endl;
}

Dog::Dog(const Dog& obj) {
    this->brain = new Brain();
    std::cout << "Dog - copy constructor has been called." << std::endl;
    *this = obj;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog - destructor has been called." << std::endl;
}

Dog& Dog::operator=(const Dog& obj) {
    std::cout << "Dog - operator= has been called." << std::endl;
    if (this != &obj) {
        this->type = obj.type;
        *this->brain = *obj.brain;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Dog - Dog sound!" << std::endl;
}

Brain* Dog::getBrain() const {
    return this->brain;
}

void Dog::printBrain() const {
    this->brain->printIdeas();
}
