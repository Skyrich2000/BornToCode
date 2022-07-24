#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat - default onstructor has been called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj) {
    std::cout << "WrongCat - copy constructor has been called." << std::endl;
    *this = obj;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat - destructor has been called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj) {
    std::cout << "WrongCat - operator= has been called." << std::endl;
    this->type = obj.type;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat - WrongCat sound!" << std::endl;
}