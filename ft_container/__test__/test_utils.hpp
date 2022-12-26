#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <numeric>
#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

std::ostringstream oss;
std::streambuf *p_cout_streambuf = std::cout.rdbuf();
int count = 0;

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
    std::string result;
    for (std::vector<std::string>::const_iterator it = strings.begin(); it != strings.end(); ++it)
    {
        if (it != strings.begin())
        {
            result += delim;
        }
        result += *it;
    }
    return result;
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

std::string get_failed_test_name(void)
{
    void *array[10];
    size_t size;
    char **strings;
    size_t i;
    std::string stack;

    size = backtrace(array, 10);
    strings = backtrace_symbols(array, size);
    for (i = 0; i < size; i++)
    {
        std::string str(strings[i]);
        if (str.find("run_test") != std::string::npos)
            break;
        stack = str;
    }
    free(strings);

    stack = stack.substr(stack.find("0x") + 1);
    stack = stack.substr(stack.find(" ") + 1);

    int d;
    char raw_name[81];
    sscanf(stack.c_str(), " _Z%d%s + %d", &d, raw_name, &d);

    std::string name(raw_name);
    return name.substr(0, name.size() - 1);
}

void expect()
{
    std::vector<std::string> expected = split(oss.str(), '\n');

    copyToCipboard("expect(\"" + join(expected, "\",\n\"") + "\");");

    std::cout.rdbuf(p_cout_streambuf);
    std::cout << "\x1B[31mTest " << count << " Failed! ... " << get_failed_test_name() << "\033[0m" << std::endl;
    std::cout << "\x1B[33mNew Snapshot Found!\033[0m" << std::endl;
    std::cout << oss.str() << std::endl;

    exit(1);
}

void expect(std::vector<std::string> str)
{

    if (std::cout.rdbuf() == p_cout_streambuf)
    {
        std::cout << "\x1B[31mERROR! please use run_test function\033[0m" << std::endl;
        exit(1);
    }

    if (trim(oss.str()) == trim(join(str, "\n")))
    {
        oss = std::ostringstream();
        return;
    }

    std::cout.rdbuf(p_cout_streambuf);
    std::cout << "\x1B[31mTest " << count << " Failed! ... " << get_failed_test_name() << "\033[0m" << std::endl;
    std::cout
        << "\x1B[32mExpected\033[0m\n"
        << trim(join(str, "\n")) << std::endl;
    std::cout << "\x1B[33mActual\033[0m\n"
              << trim(oss.str()) << std::endl;
    exit(1);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc++11-extensions"
#pragma GCC diagnostic ignored "-Wc++17-extensions"
template <typename... Types>
void expect(Types... args)
{
    std::vector<std::string> str;

    (str.push_back(args), ...);

    expect(str);
}
#pragma GCC diagnostic pop

void run_test(void (*test)())
{
    count++;
    p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    test();

    std::cout.rdbuf(p_cout_streambuf);
    std::cout << "\x1B[32mTest " << count << " ... \033[0m"
              << "✅" << std::endl;
}