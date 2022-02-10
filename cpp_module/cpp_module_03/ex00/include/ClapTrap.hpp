#ifndef CLAPTRAP_CPP
#define CLAPTRAP_CPP

#include <string>

class ClapTrap {
   private:
    std::string name;
    int hit;
    int energy;
    int damage;

   public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& obj);
    ~ClapTrap();

    ClapTrap& operator=(const ClapTrap& obj);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif