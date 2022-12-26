#include "../tree.hpp"
#include "test_utils.hpp"

void test_constructor()
{
    ft::Tree<int, int> tree;

    expect("");
}

void test_empty_tree()
{
    ft::Tree<int, int> tree;

    tree._print();

    expect("0");
}

int main()
{
    std::vector<void (*)()> list;

    list.push_back(test_constructor);
    list.push_back(test_empty_tree);

    for (std::vector<void (*)()>::iterator it = list.begin(); it != list.end(); it++)
        run_test(*it);
}
