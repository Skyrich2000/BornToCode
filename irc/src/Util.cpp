#include "Util.hpp"

Util::Util() {}

Util::Util(const Util& obj) {
    (void)obj;
}

Util::~Util() {}

Util& Util::operator=(const Util& obj) {
    (void)obj;
    return (*this);
}

std::vector<std::string> Util::split(std::string str, char Delimiter) {
    std::istringstream iss(str);  // istringstream에 str을 담는다.
    std::string buffer;           // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼

    std::vector<std::string> result;

    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (std::getline(iss, buffer, Delimiter)) {
        if (buffer.size() > 0) {
            result.push_back(buffer);
        }
    }

    return result;
}

std::string Util::join(std::vector<std::string> strs, char Delimiter) {
    std::string result;

    for (std::vector<std::string>::iterator it = strs.begin(); it != strs.end(); ++it) {
        result += Delimiter;
        result += *it;
    }
    result.erase(0, 1);

    return result;
}

std::string& Util::ltrim(std::string& s, const char* t) {
    s.erase(0, s.find_first_not_of(t));
    return s;
}

std::string& Util::rtrim(std::string& s, const char* t) {
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

std::string& Util::trim(std::string& s, const char* t) {
    return ltrim(rtrim(s, t), t);
}
