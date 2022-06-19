#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

class Span {
   private:
    unsigned int n;
    std::vector<int> v;

    Span();

   public:
    Span(unsigned int N);
    Span(const Span& obj);
    ~Span();

    Span& operator=(const Span& obj);

    void addNumber(int value);
    void addNumbers(std::vector<int>::iterator const& begin, std::vector<int>::iterator const& end);
    int shortestSpan();
    int longestSpan();

    class AlreadyExistsException : public std::exception {
        const char* what() const throw();
    };

    class FullStackException : public std::exception {
        const char* what() const throw();
    };

    class EmptyStackException : public std::exception {
        const char* what() const throw();
    };
};

#endif
