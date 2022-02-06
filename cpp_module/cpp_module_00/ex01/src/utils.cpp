#include "utils.hpp"

bool isNumber(std::string string) {
    for (std::size_t i = 0; i < string.length(); i++)
        if (!(std::isdigit(string[i]) || string[i] == '-'))
            return false;
    return true;
}

int ft_atoi(const char *str) {
    int sign;
    long long result;

    sign = 1;
    result = 0;
    while ((9 <= *str && *str <= 13) || *str == ' ')
        str++;
    if (*str == '-' || *str == '+')
        if (*str++ == '-')
            sign = -1;
    while ('0' <= *str && *str <= '9') {
        result *= 10;
        result += (*str - '0');
        if (result < 0)
            return ((sign == 1) ? -1 : 0);
        str++;
    }
    return (result * sign);
}

std::string cutByTen(std::string string) {
    if (string.length() > 10)
        string[9] = '.';
    return string.substr(0, 10);
}
