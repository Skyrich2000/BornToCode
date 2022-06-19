#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), target("") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : Form("PresidentialPardonForm", 25, 5), target(obj.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
    this->target = obj.target;
    return *this;
}

void PresidentialPardonForm::action() const {
    std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
