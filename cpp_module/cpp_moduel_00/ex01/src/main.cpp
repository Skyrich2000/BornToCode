#include <iostream>

#include "phonebook.hpp"

int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << ">>> Input command [ ADD / SEARCH / EXIT ]" << std::endl;
        if (!std::getline(std::cin, command))
            break;
        if (command == "EXIT") {
            break;
        } else if (command == "ADD") {
            if (!phonebook.addContact())
                break;
        } else if (command == "SEARCH") {
            phonebook.printSummary();
            if (!phonebook.search())
                break;
        }
    }
    return (0);
}