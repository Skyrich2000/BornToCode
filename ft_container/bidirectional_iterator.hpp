#ifndef FT_BIDIRECTIONAL_ITERATOR_HPP
#define FT_BIDIRECTIONAL_ITERATOR_HPP

#include "iterator.hpp"
#include "node.hpp"

#include <map>

namespace ft
{
    template <class Key, class Value>
    class bidirectional_iterator
    {
    private:
        typedef ft::Node<Key, Value> *node_pointer;

    public:
        typedef typename ft::iterator_traits<ft::pair<const Key, Value> *>::pointer pointer;
        // typedef ft::pair<const Key, Value> *pointer;
        typedef typename ft::iterator_traits<pointer>::value_type value_type;
        typedef typename ft::iterator_traits<pointer>::reference reference;
        typedef typename ft::iterator_traits<pointer>::difference_type difference_type;
        typedef std::bidirectional_iterator_tag iterator_category;

        bidirectional_iterator(void) : _node(NULL) {}

        bidirectional_iterator(node_pointer _node) : _node(_node) {}

        bidirectional_iterator(const bidirectional_iterator &other) : _node(other._node) {}

        bidirectional_iterator &operator=(const bidirectional_iterator &other)
        {
            if (this == &other)
                return (*this);
            this->_node = other._node;
            return (*this);
        }

        virtual ~bidirectional_iterator() {}

        // ----------------------------------------
        // operator* 연산
        // ----------------------------------------

        reference operator*()
        {
            return *this->_node->get_pair();
        }

        const reference operator*() const
        {
            return *this->_node->get_pair();
        }

        // ----------------------------------------
        // operator-> 연산
        // ----------------------------------------

        pointer operator->()
        {
            return this->_node->get_pair();
        }

        const pointer operator->() const
        {
            return this->_node->get_pair();
        }

        // ----------------------------------------
        // &operator++ 연산
        // ----------------------------------------

        bidirectional_iterator &operator++()
        {
            this->_node = this->_node->get_next();
            return (*this);
        }

        const bidirectional_iterator &operator++() const
        {
            this->_node = this->_node->get_next();
            return (*this);
        }

        // ----------------------------------------
        // operator++(int) 연산
        // ----------------------------------------

        bidirectional_iterator operator++(int)
        {
            bidirectional_iterator n(*this);
            ++(*this);
            return (n);
        }

        const bidirectional_iterator operator++(int) const
        {
            bidirectional_iterator n(*this);
            ++(*this);
            return (n);
        }

        // ----------------------------------------
        // &operator-- 연산
        // ----------------------------------------

        bidirectional_iterator &operator--()
        {
            this->_node = this->_node->get_prev();
            return (*this);
        }

        const bidirectional_iterator &operator--() const
        {
            this->_node = this->_node->get_prev();
            return (*this);
        }

        // ----------------------------------------
        // operator--(int) 연산
        // ----------------------------------------

        bidirectional_iterator operator--(int)
        {
            bidirectional_iterator n(*this);
            --(*this);
            return (n);
        }

        const bidirectional_iterator operator--(int) const
        {
            bidirectional_iterator n(*this);
            --(*this);
            return (n);
        }

        // TODO : 야매로 구현한 부분.확인 필요.
        operator bidirectional_iterator<const Key, const Value>() const
        {
            return (bidirectional_iterator<const Key, const Value>(this->_node));
        }

    private:
        node_pointer _node;
    };
};

#endif