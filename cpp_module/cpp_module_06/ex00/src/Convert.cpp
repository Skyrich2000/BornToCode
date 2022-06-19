#include "Convert.hpp"

Convert::Convert() : value(0) {}

Convert::Convert(const std::string& input) : value(std::stod(input)) {}

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
    char ch = static_cast<char>(value);

    if (isnan(value) || isinf(value)) {
        throw ImpossibleException();
    } else if (!isprint(toChar())) {
        throw NonDisplayableException();
    }

    return ch;
}

int Convert::toInt() const {
    int num = static_cast<int>(value);

    if (isnan(value) || isinf(value)) {
        throw ImpossibleException();
    } else if (std::numeric_limits<int>::max() < value || std::numeric_limits<int>::min() > value) {
        std::cout << "Int Overflow" << std::endl;
    }

    return num;
}

float Convert::toFloat() const {
    float f = static_cast<float>(value);

    return f;

    // std::cout << std::setprecision(std::numeric_limits<float>::digits10) << toFloat() << ".0f" << std::endl;
    // if (isChar == true) {
    //     return static_cast<float>(input.at(0));
    // } else {
    //     if (isNan == true) {
    //         throw ImpossibleException();
    //     } else if (isInff == true && value > 0) {
    //         throw ImpossibleException();
    //     } else if (isInff == true && value < 0) {
    //         throw ImpossibleException();
    //     }
    //     return static_cast<float>(value);
    // }
}

double Convert::toDouble() const {
    double d = static_cast<double>(value);

    return d;

    // if (isChar == true) {
    //     return static_cast<double>(input.at(0));
    // } else {
    //     if (isNan == true) {
    //         throw ImpossibleException();
    //     } else if (isInff == true && value > 0) {
    //         throw ImpossibleException();
    //     } else if (isInff == true && value < 0) {
    //         throw ImpossibleException();
    //     }
    //     return static_cast<double>(value);
    // }
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
