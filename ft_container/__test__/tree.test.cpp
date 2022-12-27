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

    tree.__print();

    expect(""
           "(-1) 0  "
           "");
}

void test_insert_one()
{
    ft::Tree<int, int> tree1;
    tree1.__insert(1, 2);
    tree1.__print();

    expect(""
           "  (-1) 1  ",
           "(-1) 0    "
           "");

    ft::Tree<int, int> tree2;
    tree2.__insert(-1, 2);
    tree2.__print();

    expect(""
           "(-1) 0     ",
           "  (-1) -1  "
           "");
}

void test_insert_both()
{
    ft::Tree<int, int> tree;

    tree.__insert(1, 2);
    tree.__insert(-1, 2);
    tree.__insert(2, 2);
    tree.__insert(0, 2);
    tree.__insert(-5, 2);
    tree.__update_height();
    tree.__print();

    expect(""
           "    (1) 2     ",
           "  (3) 1       ",
           "      (1) 0   ",
           "    (2) -1    ",
           "      (1) -5  ",
           "(-1) 0        "
           "");
}

/**
 * @see https://code-lab1.tistory.com/61
 */
void test_rotate_right()
{
    ft::Tree<int, std::string> tree;

    tree.__insert(90, "z");
    tree.__insert(60, "y");
    tree.__insert(30, "x");
    tree.__insert(99, "T1");
    tree.__insert(70, "T2");
    tree.__insert(40, "T4");
    tree.__insert(20, "T3");
    tree.__update_height();
    tree.__print(1);

    expect(""
           "    (1) 99=T1       ",
           "  (4) 90=z          ",
           "      (1) 70=T2     ",
           "    (3) 60=y        ",
           "        (1) 40=T4   ",
           "      (2) 30=x      ",
           "        (1) 20=T3   ",
           "(-1) 0=             "
           "");

    tree.__rotate_right(tree._get_head()->right);
    tree.__update_height();
    tree.__print(1);

    expect(""
           "      (1) 99=T1   ",
           "    (2) 90=z      ",
           "      (1) 70=T2   ",
           "  (3) 60=y        ",
           "      (1) 40=T4   ",
           "    (2) 30=x      ",
           "      (1) 20=T3   ",
           "(-1) 0=           "
           "");
}

void test_rotate_left()
{
    ft::Tree<int, std::string> tree;

    tree.__insert(30, "z");
    tree.__insert(60, "y");
    tree.__insert(90, "x");
    tree.__insert(20, "T1");
    tree.__insert(40, "T2");
    tree.__insert(70, "T3");
    tree.__insert(99, "T4");
    tree.__update_height();
    tree.__print(1);

    expect(""
           "        (1) 99=T4   ",
           "      (2) 90=x      ",
           "        (1) 70=T3   ",
           "    (3) 60=y        ",
           "      (1) 40=T2     ",
           "  (4) 30=z          ",
           "    (1) 20=T1       ",
           "(-1) 0=             "
           "");

    tree.__rotate_left(tree._get_head()->right);
    tree.__update_height();
    tree.__print(1);

    expect(""
           "      (1) 99=T4   ",
           "    (2) 90=x      ",
           "      (1) 70=T3   ",
           "  (3) 60=y        ",
           "      (1) 40=T2   ",
           "    (2) 30=z      ",
           "      (1) 20=T1   ",
           "(-1) 0=           "
           "");
}

void test_rotate_case_ll()
{
    ft::Tree<int, int> tree;

    tree.__insert(3, 0);
    tree.__insert(2, 0);
    tree.__insert(1, 0);
    tree.__update_height();
    tree.__print();

    expect(""
           "  (3) 3      ",
           "    (2) 2    ",
           "      (1) 1  ",
           "(-1) 0       "
           "");

    tree.__rebalance();
    tree.__print();

    expect(""
           "    (1) 3  ",
           "  (2) 2    ",
           "    (1) 1  ",
           "(-1) 0     "
           "");
}

void test_rotate_case_rr()
{
    ft::Tree<int, int> tree;

    tree.__insert(1, 0);
    tree.__insert(2, 0);
    tree.__insert(3, 0);
    tree.__update_height();
    tree.__print();

    expect(""
           "      (1) 3  ",
           "    (2) 2    ",
           "  (3) 1      ",
           "(-1) 0       "
           "");

    tree.__rebalance();
    tree.__print();

    expect(""
           "    (1) 3  ",
           "  (2) 2    ",
           "    (1) 1  ",
           "(-1) 0     "
           "");
}

void test_rotate_case_lr()
{
    ft::Tree<int, int> tree;

    tree.__insert(4, 0);
    tree.__insert(2, 0);
    tree.__insert(3, 0);
    tree.__update_height();
    tree.__print();

    expect(""
           "  (3) 4      ",
           "      (1) 3  ",
           "    (2) 2    ",
           "(-1) 0       "
           "");

    tree.__rebalance();
    tree.__print();

    expect(""
           "    (1) 4  ",
           "  (2) 3    ",
           "    (1) 2  ",
           "(-1) 0     "
           "");
}

void test_rotate_case_rl()
{
    ft::Tree<int, int> tree;

    tree.__insert(2, 0);
    tree.__insert(4, 0);
    tree.__insert(3, 0);
    tree.__update_height();
    tree.__print();

    expect(""
           "    (2) 4    ",
           "      (1) 3  ",
           "  (3) 2      ",
           "(-1) 0       "
           "");

    tree.__rebalance();
    tree.__print();

    expect(""
           "    (1) 4  ",
           "  (2) 3    ",
           "    (1) 2  ",
           "(-1) 0     "
           "");
}

void test_insert_case_ll()
{
    ft::Tree<int, int> tree;

    tree.insert(6, 0);
    tree.insert(5, 0);
    tree.insert(4, 0);
    tree.insert(3, 0);
    tree.insert(2, 0);
    tree.insert(1, 0);
    tree.__print();

    expect(""
           "      (1) 6  ",
           "    (2) 5    ",
           "      (1) 4  ",
           "  (3) 3      ",
           "    (2) 2    ",
           "      (1) 1  ",
           "(-1) 0       "
           "");
}

void test_insert_case_llrl()
{
    ft::Tree<int, int> tree;

    tree.insert(6, 0);
    tree.insert(5, 0);
    tree.insert(1, 0);
    tree.insert(2, 0);
    tree.insert(3, 0);
    tree.insert(4, 0);
    tree.__print();

    expect(""
           "      (1) 6  ",
           "    (2) 5    ",
           "      (1) 4  ",
           "  (3) 3      ",
           "    (2) 2    ",
           "      (1) 1  ",
           "(-1) 0       "
           "");
}

int main()
{
    set_test_file("tree.test.cpp");

    void (*list[])() = {
        test_constructor,
        test_empty_tree,
        test_insert_one,
        test_insert_both,
        test_rotate_right,
        test_rotate_left,
        test_rotate_case_ll,
        test_rotate_case_rr,
        test_rotate_case_lr,
        test_rotate_case_rl,
        test_insert_case_ll,
        test_insert_case_llrl,
    };

    for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++)
        run_test(list[i]);
}
