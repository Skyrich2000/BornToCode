#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Fixed& x, const Fixed& y) : x(x), y(y) {}

Point::Point(const Point& obj) : x(obj.x), y(obj.y) {}

Point::~Point() {}

const Fixed& Point::getX(void) const {
    return this->x;
}

const Fixed& Point::getY(void) const {
    return this->y;
}

Point& Point::operator=(const Point& obj) {
    (void)obj;
    return *this;
}

Point Point::operator-(const Point& obj) const {
    return (Point(this->x - obj.x, this->y - obj.y));
}

Fixed Point::operator*(const Point& obj) const {
    return (this->x * obj.x + this->y * obj.y);
}

std::ostream& operator<<(std::ostream& out, const Point& obj) {
    out << "(" << obj.getX() << "," << obj.getY() << ")";
    return out;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed zero(0);
    Point ab = b - a;
    Point bc = c - b;
    Point ca = a - c;

    Point ap = point - a;
    Point bp = point - b;
    Point cp = point - c;

    if (ab * ap > zero && bc * bp > zero && ca * cp > zero)
        return (true);
    return (false);
}