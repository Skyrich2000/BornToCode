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

        AvlNode(const typename Node<Key, Value>::pair_type &pair, AvlNode *parent, int height, int is_head = false) : Node<Key, Value>(pair, parent, NULL, NULL, is_head), height(height) {}

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

        void set_children(AvlNode *left, AvlNode *right)
        {
            this->left = left;
            this->right = right;

            if (left)
                left->parent = this;
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
            int left_height = this->left ? this->get_left()->height : 0;
            int right_height = this->right ? this->get_right()->height : 0;

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
        key_compare _comp;
        allocator_type _alloc;
        size_type _size;

    public:
        AvlTree(key_compare comp = key_compare(), allocator_type alloc = allocator_type())
        {
            // this->head = new AvlNode<Key, Value>(ft::make_pair(Key(), Value()), NULL, -1, true);
            this->head = alloc.allocate(1);
            alloc.construct(this->head, AvlNode<Key, Value>(ft::make_pair(Key(), Value()), NULL, -1, true));
            this->_comp = comp;
            this->_alloc = alloc;
            this->_size = 0;
        }

        ~AvlTree()
        {
            this->clear();
            // delete this->head;
            _alloc.destroy(this->head);
            _alloc.deallocate(this->head, 1);
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
            root = root ? root : this->head->get_right();
            root = root ? root : this->head;

            return root;
        }

        node_pointer _insert_normal(const Key &key, const Value &value, node_pointer node)
        {
            if (node == NULL)
                throw std::runtime_error("[AvlTree::_insert_normal] node is NULL");

            node_pointer child = key < node->get_pair().first ? node->get_left() : node->get_right();
            if (child)
                return this->_insert_normal(key, value, child);

            // node_pointer new_node = new AvlNode<Key, Value>(ft::make_pair(key, value), node, -1);
            node_pointer new_node = _alloc.allocate(1);
            _alloc.construct(new_node, ft::AvlNode<Key, Value>(ft::make_pair(key, value), node, -1));
            if (key < node->get_pair().first)
                node->set_children(new_node, node->get_right());
            else
                node->set_children(node->get_left(), new_node);
            this->_size++;

            return new_node;
        }

        int _update_child_height(node_pointer node)
        {
            if (node == NULL)
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
                parent->set_children(y, parent->get_right());
            else
                parent->set_children(parent->get_left(), y);
            z->set_children(y->get_right(), z->get_right());
            y->set_children(y->get_left(), z);
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
                parent->set_children(y, parent->get_right());
            else
                parent->set_children(parent->get_left(), y);
            z->set_children(z->get_left(), y->get_left());
            y->set_children(z, y->get_right());
        }

        void _rebalance(node_pointer node)
        {
            if (node == NULL || node->get_parent() == NULL)
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

        node_pointer begin()
        {
            node_pointer node = this->_get_root();
            if (node->is_head())
                return NULL;
            while (node->get_left() != NULL)
                node = node->get_left();
            return node;
        }

        node_pointer end()
        {
            node_pointer node = this->_get_root();
            if (node->is_head())
                return NULL;
            while (node->get_right() != NULL)
                node = node->get_right();
            return node;
        }

        void insert(const Key &key, const Value &value)
        {
            node_pointer node = this->_insert_normal(key, value, this->_get_root());
            this->_rebalance(node);
        }

        // copilot
        node_pointer find(const Key &key)
        {
            node_pointer node = this->_get_root();
            while (node != NULL)
            {
                if (key == node->get_pair().first)
                    return node;
                else if (key < node->get_pair().first)
                    node = node->get_left();
                else
                    node = node->get_right();
            }
            return NULL;
        }

        // copilot
        void erase(const Key &key)
        {
            node_pointer node = this->find(key);
            if (node == NULL)
                return;

            node_pointer parent = node->get_parent();
            if (node->get_left() == NULL && node->get_right() == NULL)
            {
                if (parent->get_left() == node)
                    parent->set_children(NULL, parent->get_right());
                else
                    parent->set_children(parent->get_left(), NULL);
                // delete node;
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
            }
            else if (node->get_left() == NULL || node->get_right() == NULL)
            {
                node_pointer child = node->get_left() ? node->get_left() : node->get_right();
                if (parent->get_left() == node)
                    parent->set_children(child, parent->get_right());
                else
                    parent->set_children(parent->get_left(), child);
                child->set_parent(parent);
                // delete node;
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
            }
            else
            {
                node_pointer successor = node->get_right();
                while (successor->get_left() != NULL)
                    successor = successor->get_left();

                node->set_pair(successor->get_pair());
                if (successor->get_right() != NULL)
                {
                    node_pointer child = successor->get_right();
                    if (successor->get_parent()->get_left() == successor)
                        successor->get_parent()->set_children(child, successor->get_parent()->get_right());
                    else
                        successor->get_parent()->set_children(successor->get_parent()->get_left(), child);
                    child->set_parent(successor->get_parent());
                }
                else
                {
                    if (successor->get_parent()->get_left() == successor)
                        successor->get_parent()->set_children(NULL, successor->get_parent()->get_right());
                    else
                        successor->get_parent()->set_children(successor->get_parent()->get_left(), NULL);
                }
                // delete successor;
                _alloc.destroy(successor);
                _alloc.deallocate(successor, 1);
            }

            this->_size--;
            this->_rebalance(parent);
        }

        bool empty()
        {
            return this->_size == 0;
        }

        void clear()
        {
            while (!this->empty())
                this->erase(this->_get_root()->get_pair().first);
        }

        size_type size()
        {
            return this->_size;
        }
    };
}

#endif