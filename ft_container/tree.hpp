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

        Node(const pair_type &pair, Node *parent, Node *left, Node *right, int height) : pair(pair), parent(parent), left(left), right(right), height(height) {}

        ~Node() {}

        /**
         * @debug
         */
        void print()
        {
            for (int i = 0; i < height; i++)
            {
                std::cout << " ";
            }
            std::cout << pair.first << std::endl;
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
            this->head = new Node<Key, Value>(make_pair(Key(), Value()), NULL, 0);
        }

        ~Tree() {}

    private:
        /**
         * @debug
         */
        void _print(node_pointer node)
        {
            if (node == NULL)
            {
                return;
            }
            _print(node->left);
            node->print();
            _print(node->right);
        }

    public:
        void insert(const Key &key, const Value &value)
        {

            node_pointer new_node = new Node<Key, Value>(make_pair(key, value), parent, 0);

            node_pointer node = this->head;
            node_pointer parent = NULL;
            while (node != NULL)
            {
                parent = node;
                if (key < node->pair.first)
                {
                    node = node->left;
                }
                else
                {
                    node = node->right;
                }
            }

            if (parent == NULL)
            {
                this->head = node;
            }
            else if (key < parent->pair.first)
            {
                parent->left = node;
            }
            else
            {
                parent->right = node;
            }
        }

        /**
         * @debug
         */
        void _print()
        {
            this->_print(this->head);
        }
    };
}

#endif