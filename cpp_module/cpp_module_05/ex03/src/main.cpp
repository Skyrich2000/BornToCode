#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define DEFAULT "\033[39m"

int main() {
    Intern someRandomIntern;
    Form *ppf;
    Form *rrf;
    Form *scf;
    Form *abc;

    ppf = someRandomIntern.makeForm("presidential", "Me");
    rrf = someRandomIntern.makeForm("robotomy", "Kim");
    scf = someRandomIntern.makeForm("shrubbery", "Company");
    abc = someRandomIntern.makeForm("abc", "BOSS");

    delete ppf;
    delete rrf;
    delete scf;
    delete abc;
    return 0;
}