#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : Form("ShrubberyCreationForm", 145, 137), target(obj.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
    this->target = obj.target;
    return *this;
}

void ShrubberyCreationForm::action() const {
    std::fstream output_file;

    output_file.open(this->target + "_shrubbery", std::ios::out);
    if (output_file.fail())
        throw std::exception();

    output_file << "	               ,@@@@@@@,                  \n"
                   "       ,,,.   ,@@@@@@/@@,  .oo8888o.         \n"
                   "    ,&..&%&&%,@@@@@/@@@@@@,8888/88/8o        \n"
                   "   ,%&/%&&%&&%,@@@/@@@/@@@88/88888/88'       \n"
                   "   %&&%&%&/%&&%@@/@@/ /@@@88888/88888'       \n"
                   "   %&&%/ %&..&&@@/ V /@@' `88/8 `/88'        \n"
                   "   `&%/ ` /%&'    |.|        / '|8'          \n"
                   "       |o|        | |         | |            \n"
                   "       |.|        | |         | |            \n"
                   "   /// ._///_/__/  ,/_//__///.  /_//__/_     \n";

    output_file.close();
}