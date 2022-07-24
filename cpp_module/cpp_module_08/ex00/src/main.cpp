#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main(void) {
    std::vector<int> vt;
    vt.push_back(10);
    vt.push_back(20);
    vt.push_back(30);
    vt.push_back(40);

    try {
        std::cout << *easyfind(vt, 42) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << *easyfind(vt, 30) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
