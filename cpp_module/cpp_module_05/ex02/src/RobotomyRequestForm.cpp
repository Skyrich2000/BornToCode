#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), target("") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : Form("RobotomyRequestForm", 72, 45), target(obj.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
    this->target = obj.target;
    return *this;
}

void RobotomyRequestForm::action() const {
    srand(time(NULL));
    std::cout << "drilling noises" << std::endl;
    if (rand() % 2)
        std::cout << this->target << " has been robotomized successfully!!" << std::endl;
    else
        std::cout << this->target << " failed..." << std::endl;
}