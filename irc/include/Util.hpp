#ifndef UTIL_HPP
#define UTIL_HPP

#include <sstream>
#include <string>
#include <vector>

class Util {
   public:
    Util();
    Util(const Util& obj);
    ~Util();

    Util& operator=(const Util& obj);

    static std::string& trim(std::string& s, const char* t = " \t\r\n");
    static std::string& rtrim(std::string& s, const char* t = " \t\r\n");
    static std::string& ltrim(std::string& s, const char* t = " \t\r\n");

    static std::vector<std::string> split(std::string str, char Delimiter);
    static std::string join(std::vector<std::string> strs, char Delimiter);
};

#endif
