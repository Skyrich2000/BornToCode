#ifndef FRAGTRAP_CPP
#define FRAGTRAP_CPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
   private:
   public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& obj);
    ~FragTrap();

    FragTrap& operator=(const FragTrap& obj);

    void attack(const std::string& target);
    void highFivesGuys(void);
};

#endif