#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <numeric>
#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

namespace __TEST__
{

    std::ostringstream __oss;
    std::streambuf *__p_cout_streambuf = std::cout.rdbuf();
    std::string __test_file_name = "";
    int __test_count = 0;

    const std::string _WHITESPACE = " \n\r\t\f\v";

    std::string _ltrim(const std::string &s)
    {
        size_t start = s.find_first_not_of(_WHITESPACE);
        return (start == std::string::npos) ? "" : s.substr(start);
    }

    std::string _rtrim(const std::string &s)
    {
        size_t end = s.find_last_not_of(_WHITESPACE);
        return (end == std::string::npos) ? "" : s.substr(0, end + 1);
    }

    std::string _trim(const std::string &s)
    {
        return _rtrim(_ltrim(s));
    }

    std::string _join(std::vector<std::string> const &strings, std::string delim)
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

    std::vector<std::string> _split(std::string input, char delimiter)
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

    std::string _get_failed_test_name(void)
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

    void _update_test_file(std::string output_str, std::string file_name, std::string test_name)
    {
        std::string command_get_target_line = "cat " + file_name + " | grep '" + test_name + "()' -n -A 100 | grep 'expect();' | tr '\\n' ' ' | cut -d - -f 1";
        std::string command_save_line = "LINE=$(" + command_get_target_line + ")";
        std::string command_update_line = "sed -i '' ${LINE}s/'expect();'/'" + output_str + "'/ " + file_name + "";

        std::string command = command_save_line + " && " + command_update_line;
        system(command.c_str());
    }

    void expect()
    {
        std::vector<std::string> expected = _split(__oss.str(), '\n');

        size_t max_length = 0;
        for (std::vector<std::string>::iterator it = expected.begin(); it != expected.end(); ++it)
            max_length = std::max(max_length, it->size());

        // fill with spaces
        for (std::vector<std::string>::iterator it = expected.begin(); it != expected.end(); ++it)
            it->resize(max_length + 1, ' ');

        std::string output_str = "expect(\"\"\\\n\"" + _join(expected, "\",\\\n\"") + "\"\\\n\"\");";
        std::string file_name = "tree.test.cpp";
        std::string test_name = _get_failed_test_name();

        _update_test_file(output_str, file_name, test_name);

        std::cout.rdbuf(__p_cout_streambuf);
        std::cout << "\x1B[31mTest " << __test_count << " Failed! ... " << test_name << "\033[0m" << std::endl;
        std::cout << "\x1B[33mNew Snapshot Found!\033[0m" << std::endl;
        std::cout << __oss.str() << std::endl;

        exit(1);
    }

    void expect(std::vector<std::string> str)
    {
        if (std::cout.rdbuf() == __p_cout_streambuf)
        {
            std::cout << "\x1B[31mERROR! please use run_test function\033[0m" << std::endl;
            std::cout << "\x1B[31mUsage: run_test(test_function)\033[0m" << std::endl;
            exit(1);
        }

        std::vector<std::string> expect_str = _split(__oss.str(), '\n');

        for (int i = 0; i < str.size(); i++)
            str[i] = _rtrim(str[i]);
        for (int i = 0; i < expect_str.size(); i++)
            expect_str[i] = _rtrim(expect_str[i]);

        if (_trim(_join(expect_str, "\n")) == _trim(_join(str, "\n")))
        {
            __oss = std::ostringstream();
            return;
        }

        std::cout.rdbuf(__p_cout_streambuf);
        std::cout << "\x1B[31mTest " << __test_count << " Failed! ... " << _get_failed_test_name() << "\033[0m" << std::endl;
        std::cout
            << "\x1B[32mExpected\033[0m\n"
            << _join(str, "\n") << std::endl;
        std::cout << "\x1B[33mActual\033[0m\n"
                  << __oss.str() << std::endl;
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

    void init_test(std::string file_name)
    {
        __test_file_name = file_name;
        std::cout << "\x1B[32mTest File: " << file_name << "\033[0m" << std::endl;
    }

    void run_test(void (*test)())
    {
        if (__test_file_name == "")
        {
            std::cout << "\x1B[31mERROR! please use init_test function\033[0m" << std::endl;
            std::cout << "\x1B[31mUsage: init_test(\"test_file_name.cpp\");\033[0m" << std::endl;
            exit(1);
        }

        __test_count++;
        __oss = std::ostringstream();
        __p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(__oss.rdbuf());

        test();

        std::cout.rdbuf(__p_cout_streambuf);
        std::cout << "\x1B[32mTest " << __test_count << " ... \033[0m"
                  << "✅" << std::endl;
    }
}