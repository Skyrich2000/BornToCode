#ifndef SCAVTRAP_CPP
#define SCAVTRAP_CPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
   private:
   public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& obj);
    ~ScavTrap();

    ScavTrap& operator=(const ScavTrap& obj);

    void attack(const std::string& target);
    void guardGate();
};

#endif