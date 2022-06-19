#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
   private:
    T* elements;
    unsigned int _size;

   public:
    Array() : elements(new T[0]), _size(0) {}

    Array(unsigned int n) : elements(new T[n]), _size(n) {}

    /* 같은 타입만 받아와야 하니까 <T>를 넣어야 한다. */
    Array(const Array<T>& obj) : elements(new T[obj._size]), _size(obj._size) {
        for (unsigned int i = 0; i < this->_size; i++) {
            this->elements[i] = obj.elements[i];
        }
    }

    ~Array() {
        delete[] this->elements;
    }

    Array<T>& operator=(const Array<T>& obj) {
        if (this != &obj) {
            delete[] this->elements;
            this->elements = new T[obj._size];
            this->_size = obj._size;
            for (unsigned int i = 0; i < this->_size; i++) {
                this->elements[i] = obj.elements[i];
            }
        }
        return *this;
    }

    T& operator[](unsigned int index) const {
        if (index < 0 || index >= this->_size) {
            throw std::exception();
        }
        return this->elements[index];
    }

    unsigned int size() const {
        return this->_size;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& a) {
    for (unsigned int i = 0; i < a.size(); i++) {
        out << a[i] << " ";
    }
    out << std::endl;
    return out;
}

#endif