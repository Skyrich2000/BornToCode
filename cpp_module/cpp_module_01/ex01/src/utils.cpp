#include "utils.hpp"

#include <sstream>

std::string ft_itos(int num) {
    std::string str;
    std::stringstream ss;

    ss << num;
    ss >> str;
    return str;
}