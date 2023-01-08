#ifndef FT_NODE_HPP
#define FT_NODE_HPP

#ifndef NULL
#define NULL 0
#endif

#include "util.hpp"
#include <iostream>

namespace ft
{
#define NODE_NORMAL 0
#define NODE_HEAD 1
#define NODE_TAIL 2

    template <class Key, class Value>
    class Node
    {
    private:
        int _node_type;

    protected:
        typedef ft::pair<Key, Value> pair_type;

        pair_type pair;
        Node *parent;
        Node *left;
        Node *right;

    public:
        Node(const pair_type &pair, Node *parent, Node *left, Node *right, int node_type = NODE_NORMAL) : _node_type(node_type), pair(pair), parent(parent), left(left), right(right) {}

        Node(const Node &other) : _node_type(other._node_type), pair(other.pair), parent(other.parent), left(other.left), right(other.right) {}

        virtual ~Node() {}

        Node &operator=(const Node &other)
        {
            if (this == &other)
                return (*this);
            this->_node_type = other._node_type;
            this->pair = other.pair;
            this->parent = other.parent;
            this->left = other.left;
            this->right = other.right;
            return (*this);
        }

        bool is_dummy()
        {
            return _node_type != NODE_NORMAL;
        }

        bool is_head()
        {
            return _node_type == NODE_HEAD;
        }

        bool is_tail()
        {
            return _node_type == NODE_TAIL;
        }

        void set_left(Node *node)
        {
            left = node;
        }

        void set_right(Node *node)
        {
            right = node;
        }

        void set_parent(Node *node)
        {
            parent = node;
        }

        Node *get_left()
        {
            return left;
        }

        Node *get_right()
        {
            return right;
        }

        Node *get_parent()
        {
            return parent;
        }

        pair_type *get_pair()
        {
            return &pair;
        }

        Node *get_next()
        {
            Node *next = NULL;
            if (right != NULL)
            {
                next = right;
                while (next->left != NULL)
                {
                    next = next->left;
                }
            }
            else
            {
                next = this;
                while (!next->parent->is_head() && next->parent->right == next)
                {
                    next = next->parent;
                }
                next = next->parent;
                if (next->is_head())
                {
                    throw std::out_of_range("out of range");
                }
            }
            return next;
        }

        Node *get_prev()
        {
            Node *prev = NULL;
            if (left != NULL)
            {
                prev = left;
                while (prev->right != NULL)
                {
                    prev = prev->right;
                }
            }
            else
            {
                prev = this;
                while (!prev->parent->is_head() && prev->parent->left == prev)
                {
                    prev = prev->parent;
                }
                prev = prev->parent;
                if (prev->is_head())
                {
                    throw std::out_of_range("out of range");
                }
            }
            return prev;
        }
    };

};

#endif