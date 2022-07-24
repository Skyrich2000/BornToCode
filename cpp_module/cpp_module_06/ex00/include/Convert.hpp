#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cctype>
#include <cmath>  //isnan(), isinf()
#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

#define NUMBER 0
#define CHAR 1
#define ERROR 2

class Convert {
   private:
    std::string input;
    double value;
    int type;

    Convert();
    Convert& operator=(const Convert& obj);

   public:
    Convert(const std::string& input);
    Convert(const Convert& obj);
    ~Convert();

    char toChar() const;
    int toInt() const;
    float toFloat() const;
    double toDouble() const;

    void printChar() const;
    void printInt() const;
    void printFloat() const;
    void printDouble() const;

    class NonDisplayableException : public std::exception {
        virtual const char* what() const throw();
    };

    class ImpossibleException : public std::exception {
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Convert& conv);

#endif
