#include <iostream>

#include "Harl.hpp"

int main(int argc, const char* const argv[]) {
    Harl harl;

    if (argc != 2) {
        std::cout << "[ Slient ]" << std::endl;
        return (0);
    }

    harl.complain(std::string(argv[1]));

    return (0);
}