#ifndef FT_TREE_HPP
#define FT_TREE_HPP

#include "util.hpp"
#include "node.hpp"
#include <iostream>

namespace ft
{

    template <class Key, class Value>
    class AvlNode : public Node<Key, Value>
    {
    public:
        int height;

        AvlNode(const typename Node<Key, Value>::pair_type &pair, AvlNode *parent, int height, int is_dummy = NODE_NORMAL) : Node<Key, Value>(pair, parent, NULL, NULL, is_dummy), height(height) {}

        ~AvlNode() {}

        AvlNode *get_left()
        {
            return static_cast<AvlNode *>(this->left);
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

        void set_left_child(AvlNode *left)
        {
            this->left = left;

            if (left)
                left->parent = this;
        }

        void set_right_child(AvlNode *right)
        {
            this->right = right;

            if (right)
                right->parent = this;
        }

        void set_parent(AvlNode *parent)
        {
            this->parent = parent;
        }

        void set_pair(const typename Node<Key, Value>::pair_type &pair)
        {
            this->pair = pair;
        }

        int get_balance_factor()
        {
            int left_height = _is_nil_node(this->get_left()) ? 0 : this->get_left()->height;
            int right_height = _is_nil_node(this->get_right()) ? 0 : this->get_right()->height;

            return left_height - right_height;
        }
    };

    template <
        class Key,
        class Value,
        class Compare = std::less<Key>,
        class Allocator = std::allocator<std::pair<const Key, Value> > >
    class AvlTree
    {
    public:
        typedef AvlNode<Key, Value> *node_pointer;
        typedef Compare key_compare;
        typedef typename Allocator::template rebind<ft::AvlNode<Key, Value> >::other allocator_type;
        typedef std::size_t size_type;

    private:
        node_pointer head;
        node_pointer tail;
        key_compare _comp;
        allocator_type _alloc;
        size_type _size;

    public:
        AvlTree(key_compare comp = key_compare(), allocator_type alloc = allocator_type())
        {
            // this->head = new AvlNode<Key, Value>(ft::make_pair(Key(), Value()), NULL, -1, NODE_HEAD);
            this->head = alloc.allocate(1);
            alloc.construct(this->head, AvlNode<Key, Value>(ft::make_pair(Key(), Value()), NULL, -1, NODE_HEAD));
            // this->tail = new AvlNode<Key, Value>(ft::make_pair(Key(), Value()), NULL, 999, NODE_TAIL);
            this->tail = alloc.allocate(1);
            alloc.construct(this->tail, AvlNode<Key, Value>(ft::make_pair(Key(), Value()), NULL, 999, NODE_TAIL));

            this->head->set_left_child(this->tail);
            this->head->set_right_child(this->tail);
            this->_comp = comp;
            this->_alloc = alloc;
            this->_size = 0;
        }

        ~AvlTree()
        {
            clear();
            // delete this->head;
            // delete this->tail;
            _alloc.destroy(this->head);
            _alloc.deallocate(this->head, 1);
            _alloc.destroy(this->tail);
            _alloc.deallocate(this->tail, 1);
        }

    private:
        void _print(node_pointer node, int depth = 0, int value_toggle = 0)
        {
            if (node == NULL)
                return;

            _print(node->get_right(), depth + 1, value_toggle);
            node->print(depth, value_toggle);
            _print(node->get_left(), depth + 1, value_toggle);
        }

        node_pointer _get_root()
        {
            node_pointer root = this->head->get_left();
            root = !_is_nil_node(root) ? root : this->head->get_right();
            root = !_is_nil_node(root) ? root : this->head;

            return root;
        }

        node_pointer _insert_normal(const Key &key, const Value &value, node_pointer node)
        {
            if (node == NULL)
                throw std::runtime_error("[AvlTree::_insert_normal] node is NULL");

            node_pointer child = _comp(key, node->get_pair()->first) ? node->get_left() : node->get_right();
            if (!_is_nil_node(child))
                return this->_insert_normal(key, value, child);

            // node_pointer new_node = new AvlNode<Key, Value>(ft::make_pair(key, value), node, -1);
            node_pointer new_node = _alloc.allocate(1);
            _alloc.construct(new_node, ft::AvlNode<Key, Value>(ft::make_pair(key, value), node, -1));
            if (_comp(key, node->get_pair()->first))
                node->set_left_child(new_node);
            else
                node->set_right_child(new_node);
            if (child && child->is_tail())
                new_node->set_right_child(this->tail);
            this->_size++;

            return new_node;
        }

        int _update_child_height(node_pointer node)
        {
            if (_is_nil_node(node))
                return 0;

            node->height = std::max(_update_child_height(node->get_left()), _update_child_height(node->get_right())) + 1;
            return node->height;
        }

        void _rotate_right(node_pointer node)
        {
            node_pointer parent = node->get_parent();
            if (parent == NULL)
                throw std::runtime_error("[AvlTree::_rotate_right] parent is NULL");

            node_pointer z = node;
            if (z == NULL)
                throw std::runtime_error("[AvlTree::_rotate_right] node is NULL");

            node_pointer y = z->get_left();
            if (y == NULL)
                throw std::runtime_error("[AvlTree::_rotate_right] left is NULL");

            if (parent->get_left() == z)
                parent->set_left_child(y);
            else
                parent->set_right_child(y);
            z->set_left_child(y->get_right());
            y->set_right_child(z);
        }

        void _rotate_left(node_pointer node)
        {
            node_pointer parent = node->get_parent();
            if (parent == NULL)
                throw std::runtime_error("[AvlTree::_rotate_left] parent is NULL");

            node_pointer z = node;
            if (z == NULL)
                throw std::runtime_error("[AvlTree::_rotate_left] node is NULL");

            node_pointer y = z->get_right();
            if (y == NULL)
                throw std::runtime_error("[AvlTree::_rotate_left] right is NULL");

            if (parent->get_left() == z)
                parent->set_left_child(y);
            else
                parent->set_right_child(y);
            z->set_right_child(y->get_left());
            y->set_left_child(z);
        }

        void _rebalance(node_pointer node)
        {
            if (_is_nil_node(node))
                return;

            int balance_factor = node->get_balance_factor();

            if (balance_factor > 1)
            {
                if (node->get_left() == NULL)
                    throw std::runtime_error("[AvlTree::_rebalance] left is NULL");
                if (node->get_left()->get_balance_factor() < 0)
                    this->_rotate_left(node->get_left());
                this->_rotate_right(node);
            }
            else if (balance_factor < -1)
            {
                if (node->get_right() == NULL)
                    throw std::runtime_error("[AvlTree::_rebalance] right is NULL");
                if (node->get_right()->get_balance_factor() > 0)
                    this->_rotate_right(node->get_right());
                this->_rotate_left(node);
            }

            this->_update_child_height(node);
            this->_rebalance(node->get_parent());
        }

    public:
        /**
         * @debug
         */
        void __print(int value_toggle = 0)
        {
            this->_print(this->head, 0, value_toggle);
        }

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

        node_pointer find_most_left()
        {
            node_pointer node = this->_get_root();
            while (node->get_left() != NULL)
                node = node->get_left();
            return node;
        }

        node_pointer get_tail()
        {
            return this->tail;
        }

        node_pointer insert(const Key &key, const Value &value)
        {
            node_pointer node = this->_insert_normal(key, value, this->_get_root());
            this->_rebalance(node);
            return node;
        }

        node_pointer find(const Key &key)
        {
            node_pointer node = this->_get_root();
            while (!_is_nil_node(node))
            {
                if (key == node->get_pair()->first)
                    return node;
                else if (_comp(key, node->get_pair()->first))
                    node = node->get_left();
                else
                    node = node->get_right();
            }
            return NULL;
        }

        void erase(const Key &key)
        {
            node_pointer node = this->find(key);
            if (node == NULL)
                return;

            node_pointer parent = node->get_parent();
            if (node->get_left() == NULL && node->get_right() == NULL)
            {
                if (parent->get_left() == node)
                    parent->set_left_child(NULL);
                else
                    parent->set_right_child(NULL);
                // delete node;
                if (!node->is_tail())
                {
                    _alloc.destroy(node);
                    _alloc.deallocate(node, 1);
                    this->_size--;
                }
            }
            else if (node->get_left() == NULL || node->get_right() == NULL)
            {
                node_pointer child = node->get_left() ? node->get_left() : node->get_right();
                if (parent->get_left() == node)
                    parent->set_left_child(child);
                else
                    parent->set_right_child(child);
                child->set_parent(parent);
                // delete node;
                if (!node->is_tail())
                {
                    _alloc.destroy(node);
                    _alloc.deallocate(node, 1);
                    this->_size--;
                }
            }
            else
            {
                node_pointer successor = node->get_left();
                while (successor->get_right() != NULL)
                    successor = successor->get_right();
                erase(successor->get_pair()->first);
                node->set_pair(*successor->get_pair());
            }
            this->_rebalance(parent);
        }

        bool empty()
        {
            return this->_size == 0;
        }

        void clear()
        {
            while (!this->empty())
            {
                this->erase(this->_get_root()->get_pair()->first);
            }
        }

        size_type size()
        {
            return this->_size;
        }
    };

    template <class Key, class Value>
    bool _is_nil_node(AvlNode<Key, Value> *node)
    {
        return node == NULL || node->is_dummy();
    }
}

#endif