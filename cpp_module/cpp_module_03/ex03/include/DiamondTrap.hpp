#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <string>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
   private:
    std::string name;

   public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& obj);
    ~DiamondTrap();

    DiamondTrap& operator=(const DiamondTrap& obj);

    void attack(const std::string& target);
    void whoAmI();
};

#endif
