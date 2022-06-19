#include "Convert.hpp"

int main(int argc, char **argv) {
    if (argc != 2)
        return 1;

    Convert c(argv[1]);

    std::cout << c;

    return 0;
}
