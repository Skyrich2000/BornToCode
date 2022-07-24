#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form {
   private:
    std::string target;

    RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);

   public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& obj);
    ~RobotomyRequestForm();

    void action() const;
};

#endif
