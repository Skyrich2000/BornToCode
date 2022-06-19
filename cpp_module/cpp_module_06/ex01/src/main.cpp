#include <iostream>

// https://stackoverflow.com/questions/7831696/reinterpret-cast-vs-c-style-cast
// C-style cast 와 다른점 : C-style cast는 static_cast 마냥 type을 변환하려고 하기 떄문에, 메모리 값이 변경된다.
// 그러나 reinterpret_cast는 type을 변환하지 않고, 메모리 값이 그대로 유지 된다.

struct Data {
    int x;
    int y;
};

uintptr_t serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

int main() {
    Data data;

    data.x = 1;
    data.y = 1;

    uintptr_t ptr_uint = serialize(&data);
    Data* ptr_data = deserialize(ptr_uint);

    std::cout << "< Print Pointer > " << std::endl;
    std::cout << "&data: " << &data << std::endl;
    std::cout << "ptr_uint : " << ptr_uint << std::endl;
    std::cout << "ptr_uint(hex) : " << std::hex << ptr_uint << std::endl;
    std::cout << "ptr_data : " << ptr_data << std::endl;

    std::cout << "< Print Value > " << std::endl;
    std::cout << "x : " << ptr_data->x << std::endl;
    std::cout << "y : " << ptr_data->y << std::endl;

    return 0;
}
