#include <iostream>

#include "Point.hpp"

int main(void) {
    Point a(0, 0);
    Point b(30, 0);
    Point c(0, 30);

    Point p1(10, 10);
    Point p2(-30, -50);

    std::cout << "Triangle : " << a << ' ' << b << ' ' << c << ' ' << std::endl;

    std::cout << p1;
    if (bsp(a, b, c, p1))
        std::cout << " is in the triangle" << std::endl;
    else
        std::cout << " is outside the triangle." << std::endl;

    std::cout << p2;
    if (bsp(a, b, c, p2))
        std::cout << " is in the triangle" << std::endl;
    else
        std::cout << " is outside the triangle." << std::endl;

    return 0;
}