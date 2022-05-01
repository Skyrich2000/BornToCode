#include "Harl.hpp"

#include <iostream>

void Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI just love it!\n"
              << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money.\nYou don’t put enough! If you did I would not have to ask for it!\n"
              << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming here for years and you just started working here last month.\n"
              << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now.\n"
              << std::endl;
}

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*f[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++)
        if (levels[i] == level)
            (this->*f[i])();
}