#ifndef POINT_CPP
#define POINT_CPP

#include "Fixed.hpp"

class Point {
   private:
    const Fixed x;
    const Fixed y;

   public:
    Point();
    Point(const float x, const float y);
    Point(const Fixed& x, const Fixed& y);
    Point(const Point& obj);
    ~Point();

    const Fixed& getX(void) const;
    const Fixed& getY(void) const;

    Point& operator=(const Point& obj);
    Point operator-(const Point& obj) const;
    Fixed operator*(const Point& obj) const;
};

std::ostream& operator<<(std::ostream& out, const Point& obj);

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
