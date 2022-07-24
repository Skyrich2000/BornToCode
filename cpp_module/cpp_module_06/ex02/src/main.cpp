#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

// https://velog.io/@ikmy0ung/18.10-Dynamic-casting
// Dynamic cast 는 static_cast 와 다르게 runtime 상에서 cast가 된다.

Base* generate() {
    srand((unsigned int)time(NULL));

    int i = rand() % 3;

    switch (i) {
        case 0:
            std::cout << "class A Created" << std::endl;
            return new A();
        case 1:
            std::cout << "class B Created" << std::endl;
            return new B();
        case 2:
            std::cout << "class C Created" << std::endl;
            return new C();
        default:
            return 0;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        A a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::exception& e) {
    }

    try {
        B b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } catch (std::exception& e) {
    }

    try {
        C c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (std::exception& e) {
    }
}

int main() {
    Base* base = generate();
    Base& base2 = *base;

    identify(base);
    identify(base2);
}
