#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <numeric>

std::ostringstream oss;
std::streambuf *p_cout_streambuf;

const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string &s)
{
    return rtrim(ltrim(s));
}

std::string join(std::vector<std::string> const &strings, std::string delim)
{
    if (strings.empty())
    {
        return std::string();
    }

    return std::accumulate(strings.begin() + 1, strings.end(), strings[0],
                           [&delim](std::string x, std::string y)
                           {
                               return x + delim + y;
                           });
}

std::vector<std::string> split(std::string input, char delimiter)
{
    std::vector<std::string> answer;
    std::stringstream ss(input);
    std::string temp;

    while (getline(ss, temp, delimiter))
    {
        answer.push_back(temp);
    }

    return answer;
}

void copyToCipboard(std::string str)
{
    std::string command = "echo \'" + str + "\' | pbcopy";
    system(command.c_str());
}

void expect(std::vector<std::string> str)
{
    if (str.size() == 0)
    {
        std::vector<std::string> expected = split(oss.str(), '\n');

        copyToCipboard("{\"" + join(expected, "\",\n\"") + "\"}");

        std::cout.rdbuf(p_cout_streambuf);
        std::cout << "\x1B[33mNew Snapshot Copyed!\033[0m" << std::endl;
        std::cout << oss.str() << std::endl;

        exit(1);
    }

    if (trim(oss.str()) == trim(join(str, "\n")))
    {
        return;
    }

    std::cout.rdbuf(p_cout_streambuf);
    std::cout << "\x1B[31mERROR!\033[0m" << std::endl;
    std::cout << "\x1B[32mExpected\033[0m\n"
              << trim(join(str, "\n")) << std::endl;
    std::cout << "\x1B[33mActual\033[0m\n"
              << trim(oss.str()) << std::endl;
    exit(1);
}

void init_test()
{
    p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
}