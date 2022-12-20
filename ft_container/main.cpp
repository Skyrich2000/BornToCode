#include "vector.hpp"

int main()
{
    ft::vector<int> vector_str;

    ft::vector<int>::iterator vector_str_it;

    vector_str.assign(vector_str_it, vector_str_it);

    for (int i = 0; i < vector_str.size(); i++)
        std::cout << vector_str[i] << std::endl;
}