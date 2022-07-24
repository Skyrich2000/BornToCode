#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : n(N) {}

Span::Span(const Span& obj) {
    *this = obj;
}

Span::~Span() {}

Span& Span::operator=(const Span& obj) {
    if (this != &obj) {
        this->v.clear();
        this->n = obj.n;

        for (unsigned int i = 0; i < this->n; i++) {
            this->v.push_back(obj.v[i]);
        }
    }
    return *this;
}

void Span::addNumber(int value) {
    if (this->v.size() == this->n) {
        throw Span::FullStackException();
    }
    if (std::find(this->v.begin(), this->v.end(), value) != this->v.end()) {
        throw Span::AlreadyExistsException();
    }
    this->v.push_back(value);
}

void Span::addNumbers(std::vector<int>::iterator const& begin, std::vector<int>::iterator const& end) {
    std::vector<int>::iterator iter = begin;

    for (; iter != end; iter++) {
        this->addNumber(*iter);
    }
}

int Span::shortestSpan() {
    if (this->v.size() < 2) {
        throw Span::EmptyStackException();
    }

    std::vector<int> tmp = this->v;
    int min = INT_MAX;

    std::sort(tmp.begin(), tmp.end());
    for (std::vector<int>::iterator iter = tmp.begin() + 1; iter != tmp.end(); iter++) {
        min = std::min(min, std::abs(*iter - *(iter - 1)));
    }
    return min;
}

int Span::longestSpan() {
    if (this->v.size() < 2) {
        throw Span::EmptyStackException();
    }

    return (*std::max_element(this->v.begin(), this->v.end()) - *std::min_element(this->v.begin(), this->v.end()));
}

const char* Span::AlreadyExistsException::what() const throw() {
    return "Already exists!";
}

const char* Span::FullStackException::what() const throw() {
    return "Stack is full!";
}

const char* Span::EmptyStackException::what() const throw() {
    return "Stack is empty!";
}
