#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& obj) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = obj;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& obj) {
    std::cout << "Brain assignment operator called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = obj.ideas[i];
    }
    return *this;
}

void Brain::setIdeas(std::string idea) {
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = idea;
    }
}

void Brain::printIdeas() const {
    for (int i = 0; i < 100; i++) {
        std::cout << '[' << this->ideas[i] << ']';
    }
    std::cout << std::endl;
}
