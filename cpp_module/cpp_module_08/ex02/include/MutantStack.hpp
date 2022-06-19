#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <iterator>
#include <stack>
#include <string>

template <typename T>
class MutantStack : public std::stack<T> {
   public:
    typedef typename MutantStack<T>::stack::container_type::iterator iterator;
    typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
    typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
    typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;

    MutantStack() {
        std::cout << "MutantStack default constructor called" << std::endl;
    }
    MutantStack(const MutantStack& obj) {
        std::cout << "MutantStack copy constructor called" << std::endl;
        *this = obj;
    }

    ~MutantStack() {
        std::cout << "MutantStack destructor called" << std::endl;
    }

    MutantStack& operator=(const MutantStack& obj) {
        std::cout << "MutantStack operator= called" << std::endl;
        if (this != &obj) {
            this->c = obj.c;
        }
        return *this;
    }

    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }

    const_iterator cbegin() const {
        return this->c.begin();
    }

    const_iterator cend() const {
        return this->c.end();
    }

    reverse_iterator rbegin() {
        return this->c.rbegin();
    }

    reverse_iterator rend() {
        return this->c.rend();
    }

    const_reverse_iterator crbegin() const {
        return this->c.rbegin();
    }

    const_reverse_iterator crend() const {
        return this->c.rend();
    }
};

#endif
