#include <iostream>

#include "Bureaucrat.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define DEFAULT "\033[39m"

void testErrorDecrease() {
    std::cout << BLUE << "TEST(ERROR) - DECREASE" << DEFAULT << std::endl;
    Bureaucrat ycha("ycha", 100);
    std::cout << ycha;
    try {
        ycha.decreaseGrade(100);
        std::cout << ycha;
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void testErrorIncrease() {
    std::cout << BLUE << "TEST(ERROR) - INCREASE" << DEFAULT << std::endl;
    Bureaucrat ycha("ycha", 100);
    std::cout << ycha;
    try {
        ycha.increaseGrade(100);
        std::cout << ycha;
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void testErrorInit() {
    std::cout << BLUE << "TEST(ERROR) - INIT" << DEFAULT << std::endl;
    try {
        Bureaucrat ycha("ycha", 0);
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void testSuccessDecrease() {
    std::cout << BLUE << "TEST(SUCCESS) - DECREASE" << DEFAULT << std::endl;
    Bureaucrat ycha("ycha", 6);
    std::cout << ycha;
    try {
        ycha.decreaseGrade(2);
        std::cout << ycha;
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void testSuccessIncrease() {
    std::cout << BLUE << "TEST(SUCCESS) - INCREASE" << DEFAULT << std::endl;
    Bureaucrat ycha("ycha", 10);
    std::cout << ycha;
    try {
        ycha.increaseGrade(3);
        std::cout << ycha;
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void testSuccess() {
    std::cout << BLUE << "TEST(SUCCESS)" << DEFAULT << std::endl;
    try {
        Bureaucrat ycha("ycha", 2);
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

int main() {
    testSuccess();
    testSuccessIncrease();
    testSuccessDecrease();
    testErrorInit();
    testErrorIncrease();
    testErrorDecrease();
    return 0;
}
