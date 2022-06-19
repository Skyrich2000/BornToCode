#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
   private:
    std::string target;

    PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);

   public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& obj);
    ~PresidentialPardonForm();

    void action() const;
};

#endif