#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>

#include "Weapon.hpp"

class HumanB {
   private:
    std::string name;
    Weapon *weapon;

   public:
    HumanB(const char *name);
    ~HumanB();

    void setWeapon(Weapon &weapon);
    void attack();
};

#endif