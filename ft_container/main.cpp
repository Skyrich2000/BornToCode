#include "vector.hpp"

#include <map>

int main()
{
    ft::pair<int, int> p = ft::make_pair(10, 20);

    p.first = 123;

    std::cout << p.first << std::endl;
    std::cout << p.second << std::endl;

    // ft::vector<int>::iterator vector_str_it;

    // vector_str.assign(vector_str_it, vector_str_it);

    // for (int i = 0; i < vector_str.size(); i++)
    //     std::cout << vector_str[i] << std::endl;

    // std::map<std::string, int> map;
}