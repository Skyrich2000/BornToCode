#include "contact.hpp"

#include "utils.hpp"

bool Contact::input(int index) {
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;

    std::cout << "  first name : ";
    if (!std::getline(std::cin, _first_name))
        return false;
    std::cout << "  last name : ";
    if (!std::getline(std::cin, _last_name))
        return false;
    std::cout << "  nickname : ";
    if (!std::getline(std::cin, _nickname))
        return false;
    std::cout << "  phone number : ";
    if (!std::getline(std::cin, _phone_number))
        return false;
    std::cout << "  darkest secret : ";
    if (!std::getline(std::cin, _darkest_secret))
        return false;

    this->index = index;
    this->first_name = _first_name;
    this->last_name = _last_name;
    this->nickname = _nickname;
    this->phone_number = _phone_number;
    this->darkest_secret = _darkest_secret;
    return true;
}

void Contact::print() {
    std::cout << "  first name : ";
    std::cout << this->first_name << std::endl;

    std::cout << "  last name : ";
    std::cout << this->last_name << std::endl;

    std::cout << "  nickname : ";
    std::cout << this->nickname << std::endl;

    std::cout << "  phone number : ";
    std::cout << this->phone_number << std::endl;

    std::cout << "  darkest secret : ";
    std::cout << this->darkest_secret << std::endl;
}

void Contact::printSummary() {
    std::cout << std::setw(10);
    std::cout << index << "|";

    std::cout << std::setw(10);
    std::cout << cutByTen(this->first_name) << "|";

    std::cout << std::setw(10);
    std::cout << cutByTen(this->last_name) << "|";

    std::cout << std::setw(10);
    std::cout << cutByTen(this->nickname);
    std::cout << std::endl;
}
