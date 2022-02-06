#include "phonebook.hpp"

#include "utils.hpp"

PhoneBook::PhoneBook() : index(0) {}

PhoneBook::~PhoneBook() {}

bool PhoneBook::addContact() {
    const int perIndex = this->index % MAX_CONTACTS;

    std::cout << ">>> New contact ... [" << perIndex << '/' << MAX_CONTACTS - 1 << ']' << std::endl;
    if (!this->contacts[perIndex].input(perIndex))
        return false;
    std::cout << ">>> Contact " << perIndex << " added!" << std::endl;
    this->index++;
    return true;
}

void PhoneBook::printSummary() {
    if (this->index == 0) {
        std::cout << ">>> No Contact!" << std::endl;
        return;
    }

    std::cout << std::setw(10) << "index"
              << "|"
              << std::setw(10) << "first_name"
              << "|"
              << std::setw(10) << "last_name"
              << "|"
              << std::setw(10) << "nickname" << std::endl;
    for (int i = 0; i < std::min(this->index, MAX_CONTACTS); i++) {
        this->contacts[i].printSummary();
    }
}

bool PhoneBook::search() {
    std::string input;
    int index;

    std::cout << ">>> Input contact index : ";
    if (!std::getline(std::cin, input))
        return false;

    if (!isNumber(input)) {
        std::cout << ">>> Input must be number" << std::endl;
        return true;
    }

    index = ft_atoi(input.c_str());
    if (index < 0) {
        std::cout << ">>> Input shouldn't be negative" << std::endl;
        return true;
    }
    if (index >= MAX_CONTACTS) {
        std::cout << ">>> Input cannot be greater than " << MAX_CONTACTS - 1 << std::endl;
        return true;
    }
    if (index >= this->index) {
        std::cout << ">>> Contact " << index << " does not exist" << std::endl;
        return true;
    }
    this->contacts[index].print();
    return true;
}