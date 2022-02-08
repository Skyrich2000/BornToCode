#include <iostream>

#include "Zombie.hpp"

int main(void) {
    Zombie zombie0("zombie0");
    Zombie *zombie1;

    zombie1 = newZombie("zombie1");
    zombie1->announce();

    randomChump("zombie2");

    delete zombie1;

    return (0);
}