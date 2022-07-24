#ifndef FORM_HPP
#define FORM_HPP

#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
   private:
    const std::string name;
    const int signGrade;
    const int excuteGrade;
    bool isSigned;

    Form();
    Form& operator=(const Form& obj);

   public:
    Form(const std::string name, const int signGrade, const int excuteGrade);
    Form(const Form& obj);
    virtual ~Form();

    std::string getName() const;
    int getSignGrade() const;
    int getExcuteGrade() const;
    bool getIsSigned() const;

    void beSigned(Bureaucrat& bureacrat);
    virtual void action() const = 0;
    void execute(Bureaucrat const& executor) const;

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };

    class NotSignedException : public std::exception {
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
