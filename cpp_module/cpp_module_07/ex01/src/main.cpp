#include <iostream>

#include "iter.hpp"

template <typename T>
void print(T &t) {
    std::cout << t << std::endl;
}

int main() {
    int num[5] = {1, 2, 3, 4, 5};
    std::string str[3] = {"ycha1", "ycha2", "ycha3"};

    iter(num, 5, print);
    iter(str, 3, print);

    return 0;
}
