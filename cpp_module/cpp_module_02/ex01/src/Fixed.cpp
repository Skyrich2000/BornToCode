#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(value << this->fractionalBits);
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->setRawBits((int)roundf(value * (1 << this->fractionalBits)));
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

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
    out << obj.toFloat();
    return out;
}

int Fixed::toInt(void) const {
    return (this->getRawBits() >> this->fractionalBits);
}

float Fixed::toFloat(void) const {
    return ((float)this->getRawBits() / (1 << this->fractionalBits));
}

int Fixed::getRawBits(void) const {
    return this->rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->rawBits = raw;
}