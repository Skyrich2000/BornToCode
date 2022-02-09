#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : rawBits(0) {}

Fixed::Fixed(const int value) {
    this->setRawBits(value << this->fractionalBits);
}

Fixed::Fixed(const float value) {
    this->setRawBits((int)roundf(value * (1 << this->fractionalBits)));
}

Fixed::Fixed(const Fixed& obj) {
    *this = obj;
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& obj) {
    this->setRawBits(obj.getRawBits());
    return *this;
}

bool Fixed::operator<(const Fixed& obj) const {
    return (this->getRawBits() < obj.getRawBits());
}

bool Fixed::operator>(const Fixed& obj) const {
    return (this->getRawBits() > obj.getRawBits());
}

bool Fixed::operator<=(const Fixed& obj) const {
    return (this->getRawBits() <= obj.getRawBits());
}

bool Fixed::operator>=(const Fixed& obj) const {
    return (this->getRawBits() >= obj.getRawBits());
}

bool Fixed::operator==(const Fixed& obj) const {
    return (this->getRawBits() == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed& obj) const {
    return (this->getRawBits() != obj.getRawBits());
}

Fixed Fixed::operator+(const Fixed& obj) const {
    return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed Fixed::operator-(const Fixed& obj) const {
    return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed Fixed::operator/(const Fixed& obj) const {
    return (Fixed(this->toFloat() / obj.toFloat()));
}

Fixed Fixed::operator*(const Fixed& obj) const {
    return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed& Fixed::operator++(void) {
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed& Fixed::operator--(void) {
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

const Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->operator++();
    return (temp);
}

const Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->operator--();
    return (temp);
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2) {
    return (obj1.getRawBits() < obj2.getRawBits() ? obj2 : obj1);
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2) {
    return (obj1.getRawBits() < obj2.getRawBits() ? obj1 : obj2);
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2) {
    return (obj1.getRawBits() < obj2.getRawBits() ? obj2 : obj1);
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2) {
    return (obj1.getRawBits() < obj2.getRawBits() ? obj1 : obj2);
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