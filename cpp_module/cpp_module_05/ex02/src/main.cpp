#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define DEFAULT "\033[39m"

void successTestPresi() {
    std::cout << BLUE << "TEST(SUCCESS) - PresidentialPardonForm execute" << DEFAULT << std::endl;
    try {
        Bureaucrat signer("signer", 25 - 1);
        Bureaucrat excutor("excutor", 5 - 1);
        PresidentialPardonForm form_a("form_a");
        signer.signForm(form_a);
        excutor.executeForm(form_a);
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void errorTestFormIsNotSignedPresi() {
    std::cout << BLUE << "TEST(ERROR) - PresidentialPardonForm formIsNotSigned" << DEFAULT << std::endl;
    try {
        Bureaucrat signer("signer", 25 - 1);
        Bureaucrat excutor("excutor", 5 - 1);
        PresidentialPardonForm form_a("form_a");
        excutor.executeForm(form_a);
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void errorTestGradeTooLowPresi() {
    std::cout << BLUE << "TEST(ERROR) - PresidentialPardonForm GradeTooLow" << DEFAULT << std::endl;
    try {
        Bureaucrat signer("signer", 25 - 1);
        Bureaucrat excutor("excutor", 5 + 1);
        PresidentialPardonForm form_a("form_a");
        signer.signForm(form_a);
        excutor.executeForm(form_a);
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void successTestRoboto() {
    std::cout << BLUE << "TEST(SUCCESS) - RobotomyRequestForm execute" << DEFAULT << std::endl;
    try {
        Bureaucrat signer("signer", 72 - 1);
        Bureaucrat excutor("excutor", 45 - 1);
        RobotomyRequestForm form_a("form_a");
        signer.signForm(form_a);
        excutor.executeForm(form_a);
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void errorTestFormIsNotSignedRoboto() {
    std::cout << BLUE << "TEST(ERROR) - RobotomyRequestForm formIsNotSigned" << DEFAULT << std::endl;
    try {
        Bureaucrat signer("signer", 72 - 1);
        Bureaucrat excutor("excutor", 45 - 1);
        RobotomyRequestForm form_a("form_a");
        excutor.executeForm(form_a);
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void errorTestGradeTooLowRoboto() {
    std::cout << BLUE << "TEST(ERROR) - RobotomyRequestForm GradeTooLow" << DEFAULT << std::endl;
    try {
        Bureaucrat signer("signer", 72 - 1);
        Bureaucrat excutor("excutor", 45 + 1);
        RobotomyRequestForm form_a("form_a");
        signer.signForm(form_a);
        excutor.executeForm(form_a);
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void successTestShrub() {
    std::cout << BLUE << "TEST(SUCCESS) - ShrubberyCreationForm execute" << DEFAULT << std::endl;
    try {
        Bureaucrat signer("signer", 145 - 1);
        Bureaucrat excutor("excutor", 137 - 1);
        ShrubberyCreationForm form_a("form_a");
        signer.signForm(form_a);
        excutor.executeForm(form_a);
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void errorTestFormIsNotSignedShrub() {
    std::cout << BLUE << "TEST(ERROR) - ShrubberyCreationForm formIsNotSigned" << DEFAULT << std::endl;
    try {
        Bureaucrat signer("signer", 145 - 1);
        Bureaucrat excutor("excutor", 137 - 1);
        ShrubberyCreationForm form_a("form_a");
        excutor.executeForm(form_a);
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void errorTestGradeTooLowShrub() {
    std::cout << BLUE << "TEST(ERROR) - ShrubberyCreationForm GradeTooLow" << DEFAULT << std::endl;
    try {
        Bureaucrat signer("signer", 145 - 1);
        Bureaucrat excutor("excutor", 137 + 1);
        ShrubberyCreationForm form_a("form_a");
        signer.signForm(form_a);
        excutor.executeForm(form_a);
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

int main() {
    successTestShrub();
    errorTestFormIsNotSignedShrub();
    errorTestGradeTooLowShrub();

    successTestRoboto();
    errorTestFormIsNotSignedRoboto();
    errorTestGradeTooLowRoboto();

    successTestPresi();
    errorTestFormIsNotSignedPresi();
    errorTestGradeTooLowPresi();

    return 0;
}
