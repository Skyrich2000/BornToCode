#include "../node.hpp"
#include "../util.hpp"
#include "test_utils.hpp"

using namespace __TEST__;

void test_constructor()
{
    ft::Node<int, int> node(ft::make_pair(1, 2), NULL, NULL, NULL, true);

    expect(""
           ""
           "");
}

void test_child_parent()
{
    ft::Node<int, int> node1(ft::make_pair(2, 1), NULL, NULL, NULL, true);
    ft::Node<int, int> node2(ft::make_pair(1, 2), NULL, NULL, NULL, false);
    ft::Node<int, int> node3(ft::make_pair(3, 3), NULL, NULL, NULL, false);

    node1.__set_left(&node2);
    node1.__set_right(&node3);
    node2.__set_parent(&node1);
    node3.__set_parent(&node1);

    std::cout << "node1: " << node1.get_pair().first << std::endl;
    std::cout << "node1-parent: " << node1.get_parent() << std::endl;
    std::cout << "node1-left: " << node1.get_left()->get_pair().first << std::endl;
    std::cout << "node1-right: " << node1.get_right()->get_pair().first << "\n\n";

    std::cout
        << "node2: " << node2.get_pair().first << std::endl;
    std::cout << "node2-parent: " << node2.get_parent()->get_pair().first << std::endl;
    std::cout << "node2-left: " << node2.get_left() << std::endl;
    std::cout << "node2-right: " << node2.get_right() << "\n\n";

    std::cout << "node3: " << node3.get_pair().first << std::endl;
    std::cout << "node3-parent: " << node3.get_parent()->get_pair().first << std::endl;
    std::cout << "node3-left: " << node3.get_left() << std::endl;
    std::cout << "node3-right: " << node3.get_right() << std::endl;

    expect(""
           "node1: 2          ",
           "node1-parent: 0x0 ",
           "node1-left: 1     ",
           "node1-right: 3    ",
           "                  ",
           "node2: 1          ",
           "node2-parent: 2   ",
           "node2-left: 0x0   ",
           "node2-right: 0x0  ",
           "                  ",
           "node3: 3          ",
           "node3-parent: 2   ",
           "node3-left: 0x0   ",
           "node3-right: 0x0  "
           "");
}

void test_next()
{
    ft::Node<int, int> node1(ft::make_pair(1, 1), NULL, NULL, NULL, true);
    ft::Node<int, int> node2(ft::make_pair(2, 2), NULL, NULL, NULL, false);
    ft::Node<int, int> node3(ft::make_pair(3, 3), NULL, NULL, NULL, false);

    node2.__set_left(&node1);
    node2.__set_right(&node3);
    node1.__set_parent(&node2);
    node3.__set_parent(&node2);

    std::cout << "node1: " << node1.get_pair().first << std::endl;
    std::cout << "node1-next: " << node1.get_next()->get_pair().first << "\n\n";

    std::cout << "node2: " << node2.get_pair().first << std::endl;
    std::cout << "node2-next: " << node2.get_next()->get_pair().first << "\n\n";

    // std::cout << "node3: " << node3.get_pair().first << std::endl;
    // std::cout << "node3-next: " << node3.get_next()->get_pair().first << std::endl;

    expect(""
           "node1: 1      ",
           "node1-next: 2 ",
           "              ",
           "node2: 2      ",
           "node2-next: 3 ",
           "              "
           "");
}

int main()
{
    set_test_file("node.test.cpp");

    void (*list[])() = {
        test_constructor,
        test_child_parent,
        test_next,
    };

    for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++)
        run_test(list[i]);

    // system("leaks a.out");
}
