#include "../avl_tree.hpp"
#include "test_utils.hpp"

using namespace __TEST__;

void test_constructor()
{
	ft::AvlTree<int, int> tree;

	expect(""
		   ""
		   "");
}

void test_empty_tree()
{
	ft::AvlTree<int, int> tree;

	tree.__print();

	expect(""
		   "  (999) 0  ",
		   "(-1) 0     ",
		   "  (999) 0  "
		   "");
}

void test_insert_one()
{
	ft::AvlTree<int, int> tree1;
	tree1.__insert(1, 2);
	tree1.__print();

	expect(""
		   "    (999) 0  ",
		   "  (-1) 1     ",
		   "(-1) 0       ",
		   "  (999) 0    "
		   "");

	ft::AvlTree<int, int> tree2;
	tree2.__insert(-1, 2);
	tree2.__print();

	expect(""
		   "  (999) 0    ",
		   "(-1) 0       ",
		   "    (999) 0  ",
		   "  (-1) -1    "
		   "");
}

void test_insert_both()
{
	ft::AvlTree<int, int> tree;

	tree.__insert(1, 2);
	tree.__insert(-1, 2);
	tree.__insert(2, 2);
	tree.__insert(0, 2);
	tree.__insert(-5, 2);
	tree.__update_height();
	tree.__print();

	expect(""
		   "      (999) 0  ",
		   "    (1) 2      ",
		   "  (3) 1        ",
		   "      (1) 0    ",
		   "    (2) -1     ",
		   "      (1) -5   ",
		   "(-1) 0         ",
		   "  (999) 0      "
		   "");
}

void test_erase_no_child()
{
	ft::AvlTree<int, int> tree;
	tree.insert(1, 0);
	tree.__print();

	expect(""
		   "    (999) 0  ",
		   "  (1) 1      ",
		   "(-1) 0       ",
		   "  (999) 0    "
		   "");

	tree.erase(1);
	tree.__print();

	expect(""
		   "  (999) 0  ",
		   "(-1) 0     ",
		   "  (999) 0  "
		   "");
}

void test_erase_one_child()
{
	ft::AvlTree<int, int> tree;
	tree.insert(1, 0);
	tree.insert(2, 0);
	tree.__print();

	expect(""
		   "      (999) 0  ",
		   "    (1) 2      ",
		   "  (2) 1        ",
		   "(-1) 0         ",
		   "  (999) 0      "
		   "");

	tree.erase(1);
	tree.__print();

	expect(""
		   "    (999) 0  ",
		   "  (1) 2      ",
		   "(-1) 0       ",
		   "  (999) 0    "
		   "");

	ft::AvlTree<int, int> tree2;
	tree2.insert(2, 0);
	tree2.insert(1, 0);
	tree2.__print();

	expect(""
		   "    (999) 0  ",
		   "  (2) 2      ",
		   "    (1) 1    ",
		   "(-1) 0       ",
		   "  (999) 0    "
		   "");

	tree2.erase(2);
	tree2.__print();

	expect(""
		   "    (999) 0  ",
		   "  (1) 1      ",
		   "(-1) 0       ",
		   "  (999) 0    "
		   "");
}

void test_erase_both()
{
	ft::AvlTree<int, int> tree;

	tree.insert(1, 0);
	tree.insert(2, 0);
	tree.insert(0, 0);
	tree.__print();

	expect(""
		   "      (999) 0  ",
		   "    (1) 2      ",
		   "  (2) 1        ",
		   "    (1) 0      ",
		   "(-1) 0         ",
		   "  (999) 0      "
		   "");

	tree.erase(1);
	tree.__print();

	expect(""
		   "      (999) 0  ",
		   "    (1) 2      ",
		   "  (2) 0        ",
		   "(-1) 0         ",
		   "  (999) 0      "
		   "");
}

void test_erase_not_found()
{
	ft::AvlTree<int, int> tree;

	tree.insert(1, 0);
	tree.erase(2);
	tree.__print();

	expect(""
		   "    (999) 0  ",
		   "  (1) 1      ",
		   "(-1) 0       ",
		   "  (999) 0    "
		   "");
}

void test_clear()
{
	ft::AvlTree<int, int> tree;

	tree.__insert(1, 2);
	tree.__insert(-1, 2);
	tree.__insert(2, 2);
	tree.__insert(0, 2);
	tree.__insert(-5, 2);
	tree.__update_height();
	tree.__print();

	expect(""
		   "      (999) 0  ",
		   "    (1) 2      ",
		   "  (3) 1        ",
		   "      (1) 0    ",
		   "    (2) -1     ",
		   "      (1) -5   ",
		   "(-1) 0         ",
		   "  (999) 0      "
		   "");

	tree.clear();
	tree.__print();

	expect(""
		   "  (999) 0  ",
		   "(-1) 0     ",
		   "  (999) 0  "
		   "");
}

/**
 * @see https://code-lab1.tistory.com/61
 */
void test_rotate_right()
{
	ft::AvlTree<int, std::string> tree;

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
		   "      (999) 0=      ",
		   "    (1) 99=T1       ",
		   "  (4) 90=z          ",
		   "      (1) 70=T2     ",
		   "    (3) 60=y        ",
		   "        (1) 40=T4   ",
		   "      (2) 30=x      ",
		   "        (1) 20=T3   ",
		   "(-1) 0=             ",
		   "  (999) 0=          "
		   "");

	tree.__rotate_right(tree._get_head()->get_right());
	tree.__update_height();
	tree.__print(1);

	expect(""
		   "        (999) 0=   ",
		   "      (1) 99=T1    ",
		   "    (2) 90=z       ",
		   "      (1) 70=T2    ",
		   "  (3) 60=y         ",
		   "      (1) 40=T4    ",
		   "    (2) 30=x       ",
		   "      (1) 20=T3    ",
		   "(-1) 0=            ",
		   "  (999) 0=         "
		   "");
}

void test_rotate_left()
{
	ft::AvlTree<int, std::string> tree;

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
		   "          (999) 0=   ",
		   "        (1) 99=T4    ",
		   "      (2) 90=x       ",
		   "        (1) 70=T3    ",
		   "    (3) 60=y         ",
		   "      (1) 40=T2      ",
		   "  (4) 30=z           ",
		   "    (1) 20=T1        ",
		   "(-1) 0=              ",
		   "  (999) 0=           "
		   "");

	tree.__rotate_left(tree._get_head()->get_right());
	tree.__update_height();
	tree.__print(1);

	expect(""
		   "        (999) 0=   ",
		   "      (1) 99=T4    ",
		   "    (2) 90=x       ",
		   "      (1) 70=T3    ",
		   "  (3) 60=y         ",
		   "      (1) 40=T2    ",
		   "    (2) 30=z       ",
		   "      (1) 20=T1    ",
		   "(-1) 0=            ",
		   "  (999) 0=         "
		   "");
}

void test_rotate_case_ll()
{
	ft::AvlTree<int, int> tree;

	tree.__insert(3, 0);
	tree.__insert(2, 0);
	tree.__insert(1, 0);
	tree.__update_height();
	tree.__print();

	expect(""
		   "    (999) 0  ",
		   "  (3) 3      ",
		   "    (2) 2    ",
		   "      (1) 1  ",
		   "(-1) 0       ",
		   "  (999) 0    "
		   "");

	tree.__rebalance();
	tree.__print();

	expect(""
		   "      (999) 0  ",
		   "    (1) 3      ",
		   "  (2) 2        ",
		   "    (1) 1      ",
		   "(-1) 0         ",
		   "  (999) 0      "
		   "");
}

void test_rotate_case_rr()
{
	ft::AvlTree<int, int> tree;

	tree.__insert(1, 0);
	tree.__insert(2, 0);
	tree.__insert(3, 0);
	tree.__update_height();
	tree.__print();

	expect(""
		   "        (999) 0  ",
		   "      (1) 3      ",
		   "    (2) 2        ",
		   "  (3) 1          ",
		   "(-1) 0           ",
		   "  (999) 0        "
		   "");

	tree.__rebalance();
	tree.__print();

	expect(""
		   "      (999) 0  ",
		   "    (1) 3      ",
		   "  (2) 2        ",
		   "    (1) 1      ",
		   "(-1) 0         ",
		   "  (999) 0      "
		   "");
}

void test_rotate_case_lr()
{
	ft::AvlTree<int, int> tree;

	tree.__insert(4, 0);
	tree.__insert(2, 0);
	tree.__insert(3, 0);
	tree.__update_height();
	tree.__print();

	expect(""
		   "    (999) 0  ",
		   "  (3) 4      ",
		   "      (1) 3  ",
		   "    (2) 2    ",
		   "(-1) 0       ",
		   "  (999) 0    "
		   "");

	tree.__rebalance();
	tree.__print();

	expect(""
		   "      (999) 0  ",
		   "    (1) 4      ",
		   "  (2) 3        ",
		   "    (1) 2      ",
		   "(-1) 0         ",
		   "  (999) 0      "
		   "");
}

void test_rotate_case_rl()
{
	ft::AvlTree<int, int> tree;

	tree.__insert(2, 0);
	tree.__insert(4, 0);
	tree.__insert(3, 0);
	tree.__update_height();
	tree.__print();

	expect(""
		   "      (999) 0  ",
		   "    (2) 4      ",
		   "      (1) 3    ",
		   "  (3) 2        ",
		   "(-1) 0         ",
		   "  (999) 0      "
		   "");

	tree.__rebalance();
	tree.__print();

	expect(""
		   "      (999) 0  ",
		   "    (1) 4      ",
		   "  (2) 3        ",
		   "    (1) 2      ",
		   "(-1) 0         ",
		   "  (999) 0      "
		   "");
}

void test_insert_case_ll()
{
	ft::AvlTree<int, int> tree;

	tree.insert(6, 0);
	tree.insert(5, 0);
	tree.insert(4, 0);
	tree.insert(3, 0);
	tree.insert(2, 0);
	tree.insert(1, 0);
	tree.__print();

	expect(""
		   "        (999) 0  ",
		   "      (1) 6      ",
		   "    (2) 5        ",
		   "      (1) 4      ",
		   "  (3) 3          ",
		   "    (2) 2        ",
		   "      (1) 1      ",
		   "(-1) 0           ",
		   "  (999) 0        "
		   "");
}

void test_insert_case_llrl()
{
	ft::AvlTree<int, int> tree;

	tree.insert(6, 0);
	tree.insert(5, 0);
	tree.insert(1, 0);
	tree.insert(2, 0);
	tree.insert(3, 0);
	tree.insert(4, 0);
	tree.__print();

	expect(""
		   "        (999) 0  ",
		   "      (1) 6      ",
		   "    (2) 5        ",
		   "      (1) 4      ",
		   "  (3) 3          ",
		   "    (2) 2        ",
		   "      (1) 1      ",
		   "(-1) 0           ",
		   "  (999) 0        "
		   "");
}

void test_find_most_left()
{
	ft::AvlTree<int, std::string> tree;
	tree.insert(1, "value 11111");
	tree.insert(-1, "value 11111");
	tree.insert(1, "value 11111");
	tree.insert(-2, "value 22222");
	tree.insert(3, "value 33333");
	tree.insert(-4, "value 44444");
	tree.__print();

	expect(""
		   "        (999) 0  ",
		   "      (1) 3      ",
		   "    (2) 1        ",
		   "  (3) 1          ",
		   "      (1) -1     ",
		   "    (2) -2       ",
		   "      (1) -4     ",
		   "(-1) 0           ",
		   "  (999) 0        "
		   "");

	ft::AvlTree<int, std::string>::node_pointer node2 = tree.find_most_left();
	std::cout << node2->get_pair()->first << std::endl;
	std::cout << node2->get_pair()->second << std::endl;

	expect(""
		   "-4          ",
		   "value 44444 "
		   "");
}

void test_tail()
{
	ft::AvlTree<int, std::string> tree;
	tree.insert(1, "value 11111");
	tree.insert(-1, "value 11111");
	tree.insert(1, "value 11111");
	tree.insert(-2, "value 22222");
	tree.insert(3, "value 33333");
	tree.insert(-4, "value 44444");
	tree.__print();

	expect(""
		   "        (999) 0  ",
		   "      (1) 3      ",
		   "    (2) 1        ",
		   "  (3) 1          ",
		   "      (1) -1     ",
		   "    (2) -2       ",
		   "      (1) -4     ",
		   "(-1) 0           ",
		   "  (999) 0        "
		   "");

	ft::AvlTree<int, std::string>::node_pointer tail = tree.get_tail();
	std::cout << tail->get_prev()->get_pair()->first << std::endl;

	expect(""
		   "3 "
		   "");
}

void test_find_key()
{
	ft::AvlTree<int, std::string> tree;

	tree.insert(1, "value 11111");
	tree.insert(2, "value 22222");
	tree.insert(3, "value 33333");
	ft::AvlTree<int, std::string>::node_pointer node = tree.find(2);

	std::cout << node->get_pair()->first << std::endl;
	std::cout << node->get_pair()->second << std::endl;

	expect(""
		   "2           ",
		   "value 22222 "
		   "");

	ft::AvlTree<int, std::string>::node_pointer null_node = tree.find(99);

	std::cout << null_node << std::endl;

	expect(""
		   "0x0 "
		   "");
}

void test_empty()
{
	ft::AvlTree<int, int> tree;

	std::cout << tree.empty() << std::endl;
	tree.insert(1, 0);
	std::cout << tree.empty() << std::endl;
	tree.erase(1);
	std::cout << tree.empty() << std::endl;

	expect(""
		   "1 ",
		   "0 ",
		   "1 "
		   "");
}

void test_size()
{
	ft::AvlTree<int, int> tree;

	std::cout << tree.size() << std::endl;
	tree.insert(1, 0);
	std::cout << tree.size() << std::endl;
	tree.erase(1);
	std::cout << tree.size() << std::endl;

	expect(""
		   "0 ",
		   "1 ",
		   "0 "
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
		test_erase_no_child,
		test_erase_one_child,
		test_erase_both,
		test_erase_not_found,
		test_clear,
		test_rotate_right,
		test_rotate_left,
		test_rotate_case_ll,
		test_rotate_case_rr,
		test_rotate_case_lr,
		test_rotate_case_rl,
		test_insert_case_ll,
		test_insert_case_llrl,
		test_find_most_left,
		test_tail,
		test_find_key,
		test_empty,
		test_size,
	};

	for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++)
		run_test(list[i]);

	system("leaks a.out 2>/dev/null | tail -n 4");
	// system("leaks a.out 2>/dev/null ");
}
