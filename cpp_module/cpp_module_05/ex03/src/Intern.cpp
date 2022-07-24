#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& obj) {
    (void)obj;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& obj) {
    (void)obj;
    return *this;
}

Form* Intern::makePresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

Form* Intern::makeShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

Form* Intern::makeRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

Form* Intern::makeForm(std::string formName, std::string target) {
    std::string type[3] = {"shrubbery", "robotomy", "presidential"};
    Form* (Intern::*farray[3])(std::string) = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

    for (int i = 0; i < 3; i++) {
        if (formName == type[i]) {
            std::cout << "Intern creates " << formName << " form for " << target << std::endl;
            return (this->*farray[i])(target);
        }
    }
    std::cout << "Intern cannot create " << formName << " form" << std::endl;
    return nullptr;
}
