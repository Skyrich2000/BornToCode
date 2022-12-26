#include "../tree.hpp"
#include "test_utils.hpp"

void test_constructor()
{
    ft::Tree<int, int> tree;
}

void test_print()
{
    ft::Tree<int, int> tree;

    tree._print();

    expect({"0"});
}

void test_insert()
{
    ft::Tree<int, int> tree;

    tree.insert(123, 1);
    tree._print();

    expect({"0",
            "0",
            "123"});
}

int main()
{
    init_test();

    test_constructor();
    test_print();
    test_insert();
}