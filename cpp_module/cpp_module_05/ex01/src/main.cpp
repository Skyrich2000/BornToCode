#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define DEFAULT "\033[39m"

void testSignGrade() {
    std::cout << BLUE << "TEST(ERROR) - WRONG SIGN GRADE" << DEFAULT << std::endl;
    try {
        Form b("b", 151, 1);
        std::cout << b;
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void testExecuteGrade() {
    std::cout << BLUE << "TEST(ERROR) - WRONG EXCUTE GRADE" << DEFAULT << std::endl;
    try {
        Form c("c", 1, 0);
        std::cout << c;
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void testSignCase() {
    std::cout << BLUE << "TEST(SUCCESS) - SIGN CASE" << DEFAULT << std::endl;
    try {
        Bureaucrat bu("bu", 100);
        Form form1("form1", 110, 20);
        Form form2("form2", 80, 59);

        bu.signForm(form1);
        bu.signForm(form2);
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void testSuccess() {
    std::cout << BLUE << "TEST(SUCCESS) - SIGN / EXCUTE GRADE" << DEFAULT << std::endl;
    try {
        Form a("a", 1, 1);
        std::cout << a;
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

int main() {
    testSuccess();
    testSignCase();
    testSignGrade();
    testExecuteGrade();
    return 0;
}
