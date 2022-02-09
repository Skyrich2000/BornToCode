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
    bool operator<(const Fixed& obj) const;
    bool operator>(const Fixed& obj) const;
    bool operator<=(const Fixed& obj) const;
    bool operator>=(const Fixed& obj) const;
    bool operator==(const Fixed& obj) const;
    bool operator!=(const Fixed& obj) const;

    Fixed operator+(const Fixed& obj) const;
    Fixed operator-(const Fixed& obj) const;
    Fixed operator/(const Fixed& obj) const;
    Fixed operator*(const Fixed& obj) const;

    Fixed& operator++(void);
    Fixed& operator--(void);
    const Fixed operator++(int);
    const Fixed operator--(int);

    static Fixed& max(Fixed& obj1, Fixed& obj2);
    static Fixed& min(Fixed& obj1, Fixed& obj2);
    static const Fixed& max(const Fixed& obj1, const Fixed& obj2);
    static const Fixed& min(const Fixed& obj1, const Fixed& obj2);

    int toInt(void) const;
    float toFloat(void) const;

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
