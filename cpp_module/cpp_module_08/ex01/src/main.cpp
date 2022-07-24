#include "Span.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define DEFAULT "\033[39m"

void successTestShortLong() {
    std::cout << BLUE << "TEST(SUCCESS) - shortest/longest" << DEFAULT << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void errorTestAlreadyExist() {
    std::cout << BLUE << "TEST(ERROR) - already exist" << DEFAULT << std::endl;
    try {
        Span sp = Span(10);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(11);
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void errorTestStackFull() {
    std::cout << BLUE << "TEST(ERROR) - stack full" << DEFAULT << std::endl;
    try {
        Span sp = Span(2);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void errorTestShortStackEmpty() {
    std::cout << BLUE << "TEST(ERROR) - shortest stack empty" << DEFAULT << std::endl;
    try {
        Span sp = Span(10);
        sp.shortestSpan();
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void errorTestLongStackEmpty() {
    std::cout << BLUE << "TEST(ERROR) - longest stack empty" << DEFAULT << std::endl;
    try {
        Span sp = Span(10);
        sp.longestSpan();
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void successTestAddNumbers() {
    std::cout << BLUE << "TEST(SUCCESS) - add numbers" << DEFAULT << std::endl;
    try {
        Span sp = Span(5);
        std::vector<int> v;
        v.push_back(6);
        v.push_back(3);
        v.push_back(17);
        v.push_back(9);
        sp.addNumbers(v.begin(), v.end());
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void errorTestAddNumbersFullStack() {
    std::cout << BLUE << "TEST(Error) - add numbers full stack" << DEFAULT << std::endl;
    try {
        Span sp = Span(2);
        std::vector<int> v;
        v.push_back(6);
        v.push_back(3);
        v.push_back(17);
        v.push_back(9);
        sp.addNumbers(v.begin(), v.end());
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void errorTestAddNumbersAlreadyExists() {
    std::cout << BLUE << "TEST(ERROR) - add numbers already exists" << DEFAULT << std::endl;
    try {
        Span sp = Span(10);
        std::vector<int> v;
        v.push_back(6);
        v.push_back(3);
        v.push_back(17);
        v.push_back(9);
        v.push_back(11);
        v.push_back(11);
        sp.addNumbers(v.begin(), v.end());
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

int main() {
    successTestShortLong();
    errorTestAlreadyExist();
    errorTestStackFull();
    errorTestShortStackEmpty();
    errorTestLongStackEmpty();

    successTestAddNumbers();
    errorTestAddNumbersFullStack();
    errorTestAddNumbersAlreadyExists();
    return 0;
}