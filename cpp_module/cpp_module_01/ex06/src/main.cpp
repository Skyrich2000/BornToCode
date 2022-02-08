#include <iostream>

#include "Karen.hpp"

int main(int argc, const char* const argv[]) {
    Karen karen;

    if (argc != 2) {
        std::cout << "[ Slient ]" << std::endl;
        return (0);
    }

    karen.complain(std::string(argv[1]));

    return (0);
}