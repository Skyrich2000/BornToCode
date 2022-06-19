#ifndef EASYFIND_HPP
#define EASYFIND_HPP

// https://wikidocs.net/433 - C++ 에서 typename 쓰는 이유

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end()) {
        throw std::exception();
    }
    return it;
}

#endif