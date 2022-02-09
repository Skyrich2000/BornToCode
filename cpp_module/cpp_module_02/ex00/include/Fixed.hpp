#ifndef FIXED_CPP
#define FIXED_CPP

class Fixed {
   private:
    int rawBits;
    static const int fractionalBits = 8;

   public:
    Fixed();
    Fixed(const Fixed& obj);
    ~Fixed();

    Fixed& operator=(const Fixed& obj);

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
