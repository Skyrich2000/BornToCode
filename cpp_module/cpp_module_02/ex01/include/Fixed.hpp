#ifndef FIXED_CPP
#define FIXED_CPP

#include <iostream>

class Fixed {
   private:
    int rawBits;
    static const int fractionalBits = 8;

   public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& obj);
    ~Fixed();

    Fixed& operator=(const Fixed& obj);

    int toInt(void) const;
    float toFloat(void) const;

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
