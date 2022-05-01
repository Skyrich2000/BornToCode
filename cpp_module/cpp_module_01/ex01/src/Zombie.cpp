#include "Zombie.hpp"

#include "utils.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() {
    std::cout << this->name << ": die..." << std::endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
}

void Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name) {
    return new Zombie(name);
}

void randomChump(std::string name) {
    Zombie zombie(name);
    zombie.announce();
}

Zombie* zombieHorde(int N, std::string name) {
    Zombie* zombies = new Zombie[N];

    for (int i = 0; i < N; i++) {
        zombies[i].setName(name + ft_itos(i));
    }
    return zombies;
}