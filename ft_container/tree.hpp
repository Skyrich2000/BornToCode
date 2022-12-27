#ifndef FT_TREE_HPP
#define FT_TREE_HPP

#include "util.hpp"
#include <iostream>

namespace ft
{
    template <class Key, class Value>
    class Node
    {
    public:
        typedef ft::pair<Key, Value> pair_type;

        pair_type pair;
        Node *parent;
        Node *left;
        Node *right;
        int height;

        Node(const pair_type &pair, Node *parent, int height) : pair(pair), parent(parent), left(NULL), right(NULL), height(height) {}

        ~Node() {}

        /**
         * @debug
         */
        void print(int depth, int value_toggle = 0)
        {
            for (int i = 0; i < depth; i++)
                std::cout << "  ";
            std::cout << "(" << height << ") " << pair.first;
            if (value_toggle)
                std::cout << "=" << pair.second << " ";
            std::cout << " " << std::endl;
        }

        void set_children(Node *left, Node *right)
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
            int left_height = left ? left->height : 0;
            int right_height = right ? right->height : 0;

            return left_height - right_height;
        }
    };

    template <class Key, class Value>
    class Tree
    {
    public:
        typedef Node<Key, Value> *node_pointer;

    private:
        node_pointer head;

    public:
        Tree()
        {
            this->head = new Node<Key, Value>(ft::make_pair(Key(), Value()), NULL, -1);
        }

        ~Tree() {}

    private:
        void _print(node_pointer node, int depth = 0, int value_toggle = 0)
        {
            if (node == NULL)
                return;

            _print(node->right, depth + 1, value_toggle);
            node->print(depth, value_toggle);
            _print(node->left, depth + 1, value_toggle);
        }

        node_pointer _get_root()
        {
            node_pointer root = this->head->left;
            root = root ? root : this->head->right;
            root = root ? root : this->head;

            return root;
        }

        node_pointer _insert_normal(const Key &key, const Value &value, node_pointer node)
        {
            if (node == NULL)
                throw std::runtime_error("[Tree::_insert_normal] node is NULL");

            node_pointer &child = key < node->pair.first ? node->left : node->right;

            if (child)
                return this->_insert_normal(key, value, child);

            child = new Node<Key, Value>(ft::make_pair(key, value), node, -1);
            return child;
        }

        int _update_child_height(node_pointer node)
        {
            if (node == NULL)
                return 0;

            node->height = std::max(_update_child_height(node->left), _update_child_height(node->right)) + 1;
            return node->height;
        }

        void _rotate_right(node_pointer node)
        {
            node_pointer parent = node->parent;
            if (parent == NULL)
                throw std::runtime_error("[Tree::_rotate_right] parent is NULL");

            node_pointer z = node;
            if (z == NULL)
                throw std::runtime_error("[Tree::_rotate_right] node is NULL");

            node_pointer y = z->left;
            if (y == NULL)
                throw std::runtime_error("[Tree::_rotate_right] left is NULL");

            if (parent->left == z)
                parent->set_children(y, parent->right);
            else
                parent->set_children(parent->left, y);
            z->set_children(y->right, z->right);
            y->set_children(y->left, z);
        }

        void _rotate_left(node_pointer node)
        {
            node_pointer parent = node->parent;
            if (parent == NULL)
                throw std::runtime_error("[Tree::_rotate_left] parent is NULL");

            node_pointer z = node;
            if (z == NULL)
                throw std::runtime_error("[Tree::_rotate_left] node is NULL");

            node_pointer y = z->right;
            if (y == NULL)
                throw std::runtime_error("[Tree::_rotate_left] right is NULL");

            if (parent->left == z)
                parent->set_children(y, parent->right);
            else
                parent->set_children(parent->left, y);
            z->set_children(z->left, y->left);
            y->set_children(z, y->right);
        }

        void _rebalance(node_pointer node)
        {
            if (node == NULL || node->parent == NULL)
                return;

            int balance_factor = node->get_balance_factor();

            if (balance_factor > 1)
            {
                if (node->left == NULL)
                    throw std::runtime_error("[Tree::_rebalance] left is NULL");
                if (node->left->get_balance_factor() < 0)
                    this->_rotate_left(node->left);
                this->_rotate_right(node);
            }
            else if (balance_factor < -1)
            {
                if (node->right == NULL)
                    throw std::runtime_error("[Tree::_rebalance] right is NULL");
                if (node->right->get_balance_factor() > 0)
                    this->_rotate_right(node->right);
                this->_rotate_left(node);
            }

            this->_update_child_height(node);
            this->_rebalance(node->parent);
        }

    public:
        /**
         * @debug
         */
        void __print(int value_toggle = 0)
        {
            this->_print(this->head, 0, value_toggle);
        }

        /**
         * @debug
         */
        node_pointer _get_head()
        {
            return this->head;
        }

        /**
         * @debug
         */
        void __insert(const Key &key, const Value &value)
        {
            this->_insert_normal(key, value, this->_get_root());
        }

        /**
         * @debug
         */
        void __rotate_right(node_pointer node)
        {
            this->_rotate_right(node);
        }

        /**
         * @debug
         */
        void __rotate_left(node_pointer node)
        {
            this->_rotate_left(node);
        }

        /**
         * @debug
         */
        int __update_height()
        {
            return this->_update_child_height(this->_get_root());
        }

        /**
         * @debug
         */
        void __rebalance()
        {
            this->_rebalance(this->_get_root());
        }

        void insert(const Key &key, const Value &value)
        {
            node_pointer node = this->_insert_normal(key, value, this->_get_root());
            this->_rebalance(node);
        }
    };
}

#endif