#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj) {
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj) {
    std::cout << "Assignation operator called" << std::endl;
    this->setRawBits(obj.getRawBits());
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->rawBits = raw;
}