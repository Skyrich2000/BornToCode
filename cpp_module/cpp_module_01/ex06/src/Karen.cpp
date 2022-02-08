#include "Karen.hpp"

#include <iostream>

void Karen::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI just love it!\n"
              << std::endl;
}

void Karen::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money.\nYou don’t put enough! If you did I would not have to ask for it!\n"
              << std::endl;
}

void Karen::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming here for years and you just started working here last month.\n"
              << std::endl;
}

void Karen::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now.\n"
              << std::endl;
}

Karen::Karen() {}

Karen::~Karen() {}

void Karen::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Karen::*f[4])() = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
    int i;

    for (i = 0; i < 4; i++)
        if (levels[i] == level)
            break;

    switch (i) {
        case DEBUG:
            (this->*f[DEBUG])();
        case INFO:
            (this->*f[INFO])();
        case WARNING:
            (this->*f[WARNING])();
        case ERROR:
            (this->*f[ERROR])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}