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
        void print(int value_toggle = 0)
        {
            for (int i = -1; i < height; i++)
                std::cout << "  ";
            std::cout << "(" << height << ") " << pair.first;
            if (value_toggle)
                std::cout << "=" << pair.second << " ";
            std::cout << " " << std::endl;
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
        /**
         * @debug
         */
        void _print(node_pointer node, int value_toggle = 0)
        {
            if (node == NULL)
                return;

            _print(node->right, value_toggle);
            node->print(value_toggle);
            _print(node->left, value_toggle);
        }

        node_pointer get_root()
        {
            node_pointer root = this->head->left;
            root = root ? root : this->head->right;
            root = root ? root : this->head;

            return root;
        }

        void _insert_normal(const Key &key, const Value &value, node_pointer parent)
        {
            if (parent == NULL)
                throw std::runtime_error("parent is NULL");

            node_pointer &child = key < parent->pair.first ? parent->left : parent->right;

            if (child == NULL)
                child = new Node<Key, Value>(ft::make_pair(key, value), parent, parent->height + 1);
            else
                this->_insert_normal(key, value, child);
        }

    public:
        /**
         * @debug
         */
        void
        _print(int value_toggle = 0)
        {
            this->_print(this->head, value_toggle);
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
        void _insert(const Key &key, const Value &value)
        {

            this->_insert_normal(key, value, this->get_root());
        }

        void insert(const Key &key, const Value &value)
        {
            this->_insert(key, value);
        }

        void rotate_right(node_pointer node)
        {
            if (node == NULL)
                throw std::runtime_error("node is NULL");

            node_pointer parent = node->parent;
            node_pointer left = node->left;

            if (left == NULL)
                throw std::runtime_error("left is NULL");

            node->left = left->right;
            left->right = node;

            if (parent == NULL)
                this->head = left;
            else if (parent->left == node)
                parent->left = left;
            else
                parent->right = left;

            left->parent = parent;
            node->parent = left;
        }
    };
}

#endif