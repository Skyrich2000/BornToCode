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
           "(-1) 0  "
           "");
}

void test_insert_one()
{
    ft::Tree<int, int> tree1;
    tree1._insert(1, 2);
    tree1._print();

    expect(""
           "  (0) 1  ",
           "(-1) 0   "
           "");

    ft::Tree<int, int> tree2;
    tree2._insert(-1, 2);
    tree2._print();

    expect(""
           "(-1) 0    ",
           "  (0) -1  "
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
           "      (2) 3   ",
           "    (1) 2     ",
           "  (0) 1       ",
           "      (2) 0   ",
           "    (1) -1    ",
           "      (2) -5  ",
           "(-1) 0        "
           "");
}

/**
 * @see https://code-lab1.tistory.com/61
 */
void test_rotate_right()
{
    ft::Tree<int, std::string> tree;

    tree._insert(90, "z");
    tree._insert(60, "y");
    tree._insert(30, "x");
    tree._insert(99, "T1");
    tree._insert(70, "T2");
    tree._insert(40, "T4");
    tree._insert(20, "T3");

    tree._print(1);

    expect(""
           "    (1) 99=T1       ",
           "  (0) 90=z          ",
           "      (2) 70=T2     ",
           "    (1) 60=y        ",
           "        (3) 40=T4   ",
           "      (2) 30=x      ",
           "        (3) 20=T3   ",
           "(-1) 0=             "
           "");
}

int main()
{
    init_test("tree.test.cpp");

    void (*list[])() = {
        test_constructor,
        test_empty_tree,
        test_insert_one,
        test_insert_both,
        test_rotate_right,
    };

    for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++)
        run_test(list[i]);
}
