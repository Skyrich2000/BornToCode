#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
   private:
    Form* makePresidentialPardonForm(std::string target);
    Form* makeShrubberyCreationForm(std::string target);
    Form* makeRobotomyRequestForm(std::string target);

   public:
    Intern();
    Intern(const Intern& obj);
    ~Intern();

    Intern& operator=(const Intern& obj);

    Form* makeForm(std::string formName, std::string target);
};

#endif