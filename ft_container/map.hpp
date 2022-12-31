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
        {
        protected:
            Compare comp;

        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;

            value_compare(Compare c) : comp(c) {}

            bool operator()(const value_type &lhs, const value_type &rhs) const
            {
                return comp(lhs.first, rhs.first);
            }
        };
    };
}

#endif