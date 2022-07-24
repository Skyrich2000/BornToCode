#include "Convert.hpp"

Convert::Convert() : value(0) {}

Convert::Convert(const std::string& input) {
    char* check;

    this->input = input;
    this->value = std::strtod(input.c_str(), &check);

    if (*check == 0)
        this->type = NUMBER;
    else {
        if (*check == 'f' && *(check + 1) == 0)
            this->type = NUMBER;
        else if (isascii(*check) && !isdigit(*check) && *(check + 1) == 0 && this->value == 0)
            this->type = CHAR;
        else
            this->type = ERROR;
    }
}

Convert::Convert(const Convert& obj) : value(obj.value) {
    *this = obj;
}

Convert::~Convert() {}

Convert& Convert::operator=(const Convert& obj) {
    (void)obj;
    return *this;
}

// ----------------------------------------------------------------------------

char Convert::toChar() const {
    if (this->type == ERROR)
        throw ImpossibleException();
    if (this->input == "nan" || this->input == "nanf" || this->input == "+inf" || this->input == "-inf" || this->input == "+inff" || this->input == "-inff" || this->input == "inf" || this->input == "inff")
        throw ImpossibleException();

    if (this->type == CHAR) {
        if (!isprint(input[0]))
            throw NonDisplayableException();
        return static_cast<char>(input[0]);
    }
    if (!isprint(this->value))
        throw NonDisplayableException();
    return static_cast<char>(value);
}

int Convert::toInt() const {
    if (this->type == ERROR)
        throw ImpossibleException();
    if (this->input == "nan" || this->input == "nanf" || this->input == "+inf" || this->input == "-inf" || this->input == "+inff" || this->input == "-inff" || this->input == "inf" || this->input == "inff")
        throw ImpossibleException();

    if (INT_MAX < value || INT_MIN > value)
        throw ImpossibleException();
    if (this->type == CHAR)
        return static_cast<int>(this->input[0]);
    return static_cast<int>(value);
}

float Convert::toFloat() const {
    if (this->type == ERROR)
        throw ImpossibleException();
    if (this->type == CHAR)
        return static_cast<float>(this->input[0]);
    return static_cast<float>(value);
}

double Convert::toDouble() const {
    if (this->type == ERROR)
        throw ImpossibleException();
    if (this->type == CHAR)
        return static_cast<double>(this->input[0]);
    return static_cast<double>(value);
}

// ----------------------------------------------------------------------------

void Convert::printChar() const {
    std::cout << "char: ";
    try {
        char c = this->toChar();
        std::cout << "'" << c << "'";
    } catch (const std::exception& e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

void Convert::printInt() const {
    std::cout << "int: ";
    try {
        std::cout << this->toInt();
    } catch (const std::exception& e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

void Convert::printFloat() const {
    std::cout << "float: ";
    try {
        std::cout.precision(7);
        float f = this->toFloat();
        if (f - static_cast<int>(f) == 0) {
            std::cout << f << ".0f";
        } else {
            std::cout << f << "f";
        }
    } catch (const std::exception& e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

void Convert::printDouble() const {
    std::cout << "double: ";
    try {
        std::cout.precision(15);
        float d = this->toDouble();
        if (d - static_cast<int>(d) == 0) {
            std::cout << d << ".0";
        } else {
            std::cout << d;
        }
    } catch (const std::exception& e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

// ----------------------------------------------------------------------------

const char* Convert::ImpossibleException::what() const throw() {
    return "impossible";
}

const char* Convert::NonDisplayableException::what() const throw() {
    return "Non displayable";
}

std::ostream& operator<<(std::ostream& out, const Convert& conv) {
    conv.printChar();
    conv.printInt();
    conv.printFloat();
    conv.printDouble();
    return out;
}
