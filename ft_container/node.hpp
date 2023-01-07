#ifndef FT_NODE_HPP
#define FT_NODE_HPP

#ifndef NULL
#define NULL 0
#endif

#include "util.hpp"

namespace ft
{
    template <class Key, class Value>
    class Node
    {
    private:
        bool _is_head;

    protected:
        typedef ft::pair<Key, Value> pair_type;

        pair_type pair;
        Node *parent;
        Node *left;
        Node *right;

    public:
        Node(const pair_type &pair, Node *parent, Node *left, Node *right, bool is_head = false) : _is_head(is_head), pair(pair), parent(parent), left(left), right(right) {}

        virtual ~Node() {}

        bool is_head()
        {
            return _is_head;
        }

        /**
         * @debug
         */
        void __set_left(Node *node)
        {
            left = node;
        }

        /**
         * @debug
         */
        void __set_right(Node *node)
        {
            right = node;
        }

        /**
         * @debug
         */
        void __set_parent(Node *node)
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
                while (prev->parent != NULL && prev->parent->left == prev)
                {
                    prev = prev->parent;
                }
                prev = prev->parent;
            }
            return prev;
        }
    };

};

#endif