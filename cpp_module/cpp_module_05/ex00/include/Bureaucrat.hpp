#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
   private:
    const std::string name;
    int grade;

    Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& obj);

   public:
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& obj);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    void increaseGrade(int number);
    void decreaseGrade(int number);

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureacrat);

#endif
