#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
   protected:
    std::string type;

   public:
    Animal();
    Animal(std::string type);
    Animal(const Animal& obj);
    virtual ~Animal();

    Animal& operator=(const Animal& obj);

    std::string getType() const;
    virtual void makeSound() const;
};

#endif
