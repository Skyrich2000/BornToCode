#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
   private:
    std::string type;

   public:
    Weapon(const char *type);
    ~Weapon();

    std::string getType() const;
    void setType(const char *type);
};

#endif