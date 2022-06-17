#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void testLeak() {
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    delete j;
    delete i;
}

void testArray() {
    const Animal *animals[4];

    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0) {
            animals[i] = new Cat();
        } else {
            animals[i] = new Dog();
        }
    }

    std::cout << std::endl;

    for (int i = 0; i < 4; i++) {
        delete animals[i];
    }
}

void testDeepCopy() {
    Cat *cat1 = new Cat();
    Cat *cat2 = new Cat();

    cat1->getBrain()->setIdeas("1️⃣");
    cat2->getBrain()->setIdeas("2️⃣");

    cat1->printBrain();
    cat2->printBrain();

    *cat2 = *cat1;
    delete cat1;

    cat2->printBrain();

    delete cat2;
}

void testAbstract() {
    Animal *animal = new Animal();
    animal->makeSound();
    delete animal;
}

int main() {
    testAbstract();
    std::cout << "-------------------\n\n\n"
              << std::endl;

    testLeak();
    std::cout << "-------------------\n\n\n"
              << std::endl;
    testArray();
    std::cout << "-------------------\n\n\n"
              << std::endl;
    testDeepCopy();
    std::cout << "-------------------\n\n\n"
              << std::endl;
    std::cout << system("leaks a.out | tail") << std::endl;
    return 0;
}