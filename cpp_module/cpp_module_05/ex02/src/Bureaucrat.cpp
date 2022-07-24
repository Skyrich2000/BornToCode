#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("noname"), grade(1) {
    std::cout << "Bureaucrat [" << this->name << "] - constructor has been called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
    std::cout << "Bureaucrat [" << this->name << "] - constructor has been called." << std::endl;
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name), grade(obj.grade) {
    std::cout << "Bureaucrat [" << this->name << "] - copy constructor has been called." << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat [" << this->name << "] - destructor has been called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
    std::cout << "Bureaucrat [" << this->name << "] - operator= called" << std::endl;
    if (this != &obj) {
        this->grade = obj.grade;
    }
    return *this;
}

std::string Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::increaseGrade(int number) {
    int _grade = this->grade - number;

    if (_grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (_grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade = _grade;
}

void Bureaucrat::decreaseGrade(int number) {
    int _grade = this->grade + number;

    if (_grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (_grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade = _grade;
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << "Bureaucrat [" << this->name << "] signs " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Bureaucrat [" << this->name << "] cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(Form const& form) {
    try {
        form.execute(*this);
        std::cout << "Bureaucrat [" << this->name << "] executed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Bureaucrat [" << this->name << "] cannot executed " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade Too High!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade Too Low!";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureacrat) {
    out << "name : " << bureacrat.getName() << ", grade : " << bureacrat.getGrade() << std::endl;
    return out;
}
