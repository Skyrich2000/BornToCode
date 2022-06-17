#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
   private:
    std::string ideas[100];

   public:
    Brain();
    Brain(const Brain& obj);
    ~Brain();

    Brain& operator=(const Brain& obj);

    void setIdeas(std::string idea);
    void printIdeas() const;
};

#endif
