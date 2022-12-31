// #include "vector.hpp"

#include <iostream>

#include "node.hpp"

template <class Key, class Value>
class AvlNode : public ft::Node<Key, Value>
{
public:
    int height;

    AvlNode(const typename ft::Node<Key, Value>::pair_type &pair, AvlNode *parent, int height) : ft::Node<Key, Value>(pair, parent), height(height) {}

    ~AvlNode() {}

    AvlNode &get_left()
    {
        return static_cast<AvlNode &>(this->left);
    }

    AvlNode *get_right()
    {
        return static_cast<AvlNode *>(this->right);
    }

    AvlNode *get_parent()
    {
        return static_cast<AvlNode *>(this->parent);
    }

    /**
     * @debug
     */
    void print(int depth, int value_toggle = 0)
    {
        for (int i = 0; i < depth; i++)
            std::cout << "  ";
        std::cout << "(" << height << ") " << this->pair.first;
        if (value_toggle)
            std::cout << "=" << this->pair.second << " ";
        std::cout << " " << std::endl;
    }

    void set_parent(AvlNode *parent)
    {
        this->parent = parent;
    }

    void set_children(AvlNode *left, AvlNode *right)
    {
        this->left = left;
        this->right = right;

        if (left)
            left->parent = this;
        if (right)
            right->parent = this;
    }

    int get_balance_factor()
    {
        int left_height = this->left ? this->get_left()->height : 0;
        int right_height = this->right ? this->get_right()->height : 0;

        return left_height - right_height;
    }
};

// template <class Key, class Value>
// void _print(AvlNode<Key, Value> *node, int depth = 0, int value_toggle = 0)
// {
//     if (node == NULL)
//         return;

//     _print(node->get_right(), depth + 1, value_toggle);
//     node->print(depth, value_toggle);
//     _print(node->get_left(), depth + 1, value_toggle);
// }

int main()
{
    AvlNode<int, int> *n1 = new AvlNode<int, int>(ft::pair<int, int>(1, 1), NULL, 1);
    AvlNode<int, int> *n2 = new AvlNode<int, int>(ft::pair<int, int>(1, 1), NULL, 1);
    AvlNode<int, int> *n3 = new AvlNode<int, int>(ft::pair<int, int>(1, 1), NULL, 1);

    // n1->set_children(n2, n3);

    // _print(n1, 0, 1);

    AvlNode<int, int> &node = n1->get_left();
}