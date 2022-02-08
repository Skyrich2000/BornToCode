#include <iostream>
#include <string>

int main(void) {
    std::string mystring("HI THIS IS BRAIN");
    std::string* stringPTR = &mystring;
    std::string& stringREF = mystring;

    std::cout << "PRINT ADDRESS" << std::endl;
    std::cout << "origin : " << &mystring << std::endl;
    std::cout << "pointer : " << stringPTR << std::endl;
    std::cout << "reference : " << &stringREF << std::endl;
    std::cout << std::endl;

    std::cout << "PRINT VALUE" << std::endl;
    std::cout << "pointer : " << *stringPTR << std::endl;
    std::cout << "reference : " << stringREF << std::endl;
    std::cout << std::endl;

    return (0);
}