#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include "bidirectional_iterator.hpp"
#include "avl_tree.hpp"

namespace ft
{
    template <
        class Key,
        class Value,
        class Compare = std::less<Key>,
        class Allocator = std::allocator<std::pair<const Key, Value> > >
    class map
    {
    public:
        typedef Key key_type;
        typedef Value mapped_type;
        typedef ft::pair<const Key, mapped_type> value_type;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef Compare key_compare;
        typedef Allocator allocator_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef typename Allocator::pointer pointer;
        typedef typename Allocator::const_pointer const_pointer;
        typedef ft::bidirectional_iterator<Key, Value> iterator;
        typedef ft::bidirectional_iterator<const Key, const Value> const_iterator;
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
        typedef typename ft::AvlTree<Key, Value, Compare, Allocator> tree;

        Compare _comp;
        Allocator _alloc;
        tree *_tree;

        template <class T>
        void _swap(T &a, T &b)
        {
            T tmp = a;
            a = b;
            b = tmp;
        }

    public:
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
        {
            _tree = new ft::AvlTree<Key, Value, Compare, Allocator>(comp, alloc);
            _comp = comp;
            _alloc = alloc;
        }

        // copilot
        template <class InputIterator>
        map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
        {
            _tree = new ft::AvlTree<Key, Value, Compare, Allocator>(comp, alloc);
            _comp = comp;
            _alloc = alloc;
            insert(first, last);
        }

        // copilot
        map(const map &x)
        {
            _tree = new ft::AvlTree<Key, Value, Compare, Allocator>(x._comp, x._alloc);
            _comp = x._comp;
            _alloc = x._alloc;
            insert(x.begin(), x.end());
        }

        // copilot
        ~map()
        {
            delete _tree;
        }

        // TODO: debug!!!!!
        tree *___get_tree()
        {
            return _tree;
        }

        iterator begin()
        {
            return iterator(_tree->find_most_left());
        }

        const_iterator begin() const
        {
            // return iterator(_tree->begin());
            return iterator(_tree->find_most_left());
        }

        iterator end()
        {
            return iterator(_tree->get_tail());
        }

        const_iterator end() const
        {
            // return const_iterator(_tree->end());
            return iterator(_tree->get_tail());
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }

        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(end());
        }

        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }

        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(begin());
        }

        bool empty() const
        {
            return _tree->empty();
        }

        size_type size() const
        {
            return _tree->size();
        }

        // copy
        size_type max_size() const
        {
            return (_alloc.max_size());
        }

        map &operator=(const map &x)
        {
            clear();
            insert(x.begin(), x.end());
            return *this;
        }

        mapped_type &operator[](const key_type &k)
        {
            typename tree::node_pointer node = _tree->find(k);

            if (!node)
                node = _tree->insert(k, mapped_type());
            return node->get_pair()->second;
        }

        ft::pair<iterator, bool> insert(const value_type &val)
        {
            ft::pair<iterator, bool> ret;

            if (_tree->find(val.first) != NULL)
            {
                ret.first = iterator(_tree->find(val.first));
                ret.second = false;
                return ret;
            }
            ret.first = iterator(_tree->insert(val.first, val.second));
            ret.second = true;
            return ret;
        }

        iterator insert(iterator position, const value_type &val)
        {
            (void)position;
            return insert(val).first;
        }

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                insert(*first);
                first++;
            }
        }

        void erase(iterator position)
        {
            _tree->erase(position->first);
        }

        size_type erase(const key_type &k)
        {
            size_type size = _tree->size();
            _tree->erase(k);
            return size - _tree->size();
        }

        void erase(iterator first, iterator last)
        {
            while (first != last)
            {
                iterator index = first;
                ++first;
                erase(index);
            }
        }

        void swap(map &x)
        {
            _swap(_tree, x._tree);
            _swap(_comp, x._comp);
        }

        void clear()
        {
            _tree->clear();
        }

        key_compare key_comp() const
        {
            return (this->_comp);
        }

        value_compare value_comp() const
        {
            return (value_compare(this->_comp));
        }

        iterator find(const key_type &k)
        {
            typename tree::node_pointer node = _tree->find(k);

            if (node)
                return iterator(node);
            return end();
        }

        const_iterator find(const key_type &k) const
        {
            typename tree::node_pointer node = _tree->find(k);

            // if (node)
            //     return const_iterator(node);
            if (node)
                return iterator(node);
            return end();
        }

        size_type count(const key_type &k) const
        {
            if (_tree->find(k))
                return 1;
            return 0;
        }

        // copilot
        iterator lower_bound(const key_type &k)
        {
            iterator it = begin();
            while (it != end())
            {
                if (!_comp(it->first, k))
                    return it;
                it++;
            }
            return it;
        }

        // copilot
        const_iterator lower_bound(const key_type &k) const
        {
            const_iterator it = begin();
            while (it != end())
            {
                if (!_comp(it->first, k))
                    return it;
                it++;
            }
            return it;
        }

        // copilot
        iterator upper_bound(const key_type &k)
        {
            iterator it = begin();
            while (it != end())
            {
                if (_comp(k, it->first))
                    return it;
                it++;
            }
            return it;
        }

        // copilot
        const_iterator upper_bound(const key_type &k) const
        {
            const_iterator it = begin();
            while (it != end())
            {
                if (_comp(k, it->first))
                    return it;
                it++;
            }
            return it;
        }

        // copilot
        ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
        {
            return ft::make_pair(lower_bound(k), upper_bound(k));
        }

        // copilot
        ft::pair<iterator, iterator> equal_range(const key_type &k)
        {
            return ft::make_pair(lower_bound(k), upper_bound(k));
        }

        allocator_type get_allocator() const
        {
            return this->_alloc;
        }
    };

    // copy
    template <class Key, class T, class Compare, class Alloc>
    bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) { return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }
    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) { return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }
    template <class Key, class T, class Compare, class Alloc>
    bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) { return !(lhs == rhs); }
    template <class Key, class T, class Compare, class Alloc>
    bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) { return !(rhs < lhs); }
    template <class Key, class T, class Compare, class Alloc>
    bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) { return (rhs < lhs); }
    template <class Key, class T, class Compare, class Alloc>
    bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) { return !(lhs < rhs); }
}

#endif