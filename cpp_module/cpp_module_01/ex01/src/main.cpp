#include <iostream>

#include "Zombie.hpp"

#define N 4

int main(void) {
    Zombie* zombies = zombieHorde(N, "ycha");

    for (int i = 0; i < N; i++) {
        zombies[i].announce();
    }

    delete[] zombies;

    return (0);
}