#include "../tree.hpp"
#include "test_utils.hpp"

using namespace __TEST__;

void test_constructor()
{
    ft::Tree<int, int> tree;

    expect(""
           ""
           "");
}

void test_empty_tree()
{
    ft::Tree<int, int> tree;

    tree._print();

    expect(""
           "(0) 0 "
           "");
}

void test_insert_left()
{
    ft::Tree<int, int> tree;

    tree._insert(1, 2);

    tree._print();

    expect(""
           "(0) 0    ",
           "  (1) 1  "
           "");
}

void test_insert_right()
{
    ft::Tree<int, int> tree;

    tree._insert(-1, 2);

    tree._print();

    expect(""
           "  (1) -1  ",
           "(0) 0     "
           "");
}

void test_insert_both()
{
    ft::Tree<int, int> tree;

    tree._insert(1, 2);
    tree._insert(-1, 2);
    tree._insert(2, 2);
    tree._insert(0, 2);
    tree._insert(-5, 2);
    tree._insert(3, 2);

    tree._print();

    expect(""
           "    (2) -5   ",
           "  (1) -1     ",
           "(0) 0        ",
           "    (2) 0    ",
           "  (1) 1      ",
           "    (2) 2    ",
           "      (3) 3  "
           "");
}

void test_rotate_right()
{
    ft::Tree<int, int> tree;

    tree._insert(1, 2);
    tree._insert(-1, 2);
    tree._insert(2, 2);
    tree._insert(0, 2);
    tree._insert(-5, 2);
    tree._insert(3, 2);

    tree._print(1);

    expect(""
           "    (2) -5=2    ",
           "  (1) -1=2      ",
           "(0) 0=0         ",
           "    (2) 0=2     ",
           "  (1) 1=2       ",
           "    (2) 2=2     ",
           "      (3) 3=2   "
           "");
}

int main()
{
    init_test("tree.test.cpp");

    void (*list[])() = {
        test_constructor,
        test_empty_tree,
        test_insert_left,
        test_insert_right,
        test_insert_both,
        test_rotate_right,
    };

    for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++)
        run_test(list[i]);
}
