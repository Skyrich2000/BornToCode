#include "Form.hpp"

Form::Form() : name("noname"), signGrade(1), excuteGrade(1), isSigned(false) {
    std::cout << "Form [" << this->name << "] - constructor has been called." << std::endl;
}

Form::Form(const Form& obj) : name(obj.getName()), signGrade(obj.getSignGrade()), excuteGrade(obj.getExcuteGrade()), isSigned(obj.getIsSigned()) {
    std::cout << "Form [" << this->name << "] - copy constructor has been called." << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int excuteGrade) : name(name), signGrade(signGrade), excuteGrade(excuteGrade), isSigned(false) {
    std::cout << "Form [" << this->name << "] - constructor has been called." << std::endl;
    if (signGrade < 1 || excuteGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || excuteGrade > 150)
        throw GradeTooLowException();
}

Form::~Form() {
    std::cout << "Form [" << this->name << "] - destructor has been called." << std::endl;
}

Form& Form::operator=(const Form& obj) {
    std::cout << "Form [" << this->name << "] - operator= called" << std::endl;
    if (this != &obj) {
        this->isSigned = obj.getIsSigned();
    }
    return *this;
}

std::string Form::getName() const {
    return this->name;
}

int Form::getSignGrade() const {
    return this->signGrade;
}

int Form::getExcuteGrade() const {
    return this->excuteGrade;
}

bool Form::getIsSigned() const {
    return this->isSigned;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
    if (this->getSignGrade() < bureaucrat.getGrade()) {
        throw GradeTooLowException();
    }
    this->isSigned = true;
}

void Form::execute(Bureaucrat const& bureaucrat) const {
    if (this->getExcuteGrade() < bureaucrat.getGrade()) {
        throw GradeTooLowException();
    }
    if (!this->getIsSigned()) {
        throw NotSignedException();
    }
    this->action();
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is Too High";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is Too Low";
}

const char* Form::NotSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "name : " << form.getName() << ", signGrade : " << form.getSignGrade() << ", executeGrade : " << form.getExcuteGrade() << ", isSign : " << form.getIsSigned() << std::endl;
    return out;
}
