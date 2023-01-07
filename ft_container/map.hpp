#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include "bidirectional_iterator.hpp"

namespace ft
{
    template <
        class Key,
        class T,
        class Compare = std::less<Key>,
        class Allocator = std::allocator<std::pair<const Key, T> > >
    class map
    {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef ft::pair<const Key, mapped_type> value_type;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef Compare key_compare;
        typedef Allocator allocator_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef typename Allocator::pointer pointer;
        typedef typename Allocator::const_pointer const_pointer;
        typedef ft::bidirectional_iterator<value_type> iterator;
        typedef ft::bidirectional_iterator<const value_type> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

        class value_compare
        { // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
            friend class map;

        protected:
            Compare comp;
            value_compare(Compare c) : comp(c) {} // constructed with map's comparison object
        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            bool operator()(const value_type &x, const value_type &y) const
            {
                return comp(x.first, y.first);
            }
        };

    private:
        typedef typename ft::AvlTree<value_type, Compare, node_allocator> tree;

        Compare _comp;
        tree _tree;

    public:
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
        {
            _tree = new ft::AvlTree<value_type, Compare, node_allocator>(comp, alloc);
            _comp = comp;
        }

        // template <class InputIterator>
        // map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) {}

        // map(const map &x) {}

        iterator begin()
        {
            return _tree->begin();
        }

        ft::pair<iterator, bool> insert(const value_type &val)
        {
            ft::pair<iterator, bool> ret;

            if (_tree->find(val.first) != _tree->end())
            {
                ret.first = _tree->find(val.first);
                ret.second = false;
                return ret;
            }

            ret.first = _tree->insert(val);
            ret.second = true;
            return ret;
        }

        iterator insert(iterator position, const value_type &val)
        {
            (void)position;
            return _tree->insert(val);
        }
    };
}

#endif