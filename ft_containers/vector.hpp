#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>

#include "util.hpp"
#include "random_access_iterator.hpp"

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename allocator_type::size_type size_type;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef ft::random_access_iterator<value_type> iterator;
        typedef ft::random_access_iterator<const value_type> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

    private:
        pointer _base;
        size_type _size;
        size_type _capacity;
        allocator_type _alloc;

        template <class U>
        void _swap(U &a, U &b)
        {
            U tmp = a;
            a = b;
            b = tmp;
        }

        template <class InputIterator>
        typename iterator_traits<InputIterator>::difference_type _distance(InputIterator first, InputIterator last)
        {
            typename iterator_traits<InputIterator>::difference_type n = 0;
            while (first != last)
            {
                first++;
                n++;
            }
            return (n);
        }

        void free_base()
        {
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(&_base[i]);
            _alloc.deallocate(_base, _capacity);
            _size = 0;
            _capacity = 0;
        }

    public:
        explicit vector(const allocator_type &alloc = allocator_type()) : _base(NULL), _size(0), _capacity(0), _alloc(alloc) {}

        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
        {
            _alloc = alloc;
            _base = _alloc.allocate(n);
            _size = n;
            _capacity = n;
            for (size_type i = 0; i < n; i++)
                _base[i] = val;
        }

        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL)
        {
            difference_type n = _distance(first, last);

            _alloc = alloc;
            _base = _alloc.allocate(n);
            _size = n;
            _capacity = n;
            assign(first, last);
        }

        vector(const vector &x)
        {
            _alloc = x._alloc;
            _base = _alloc.allocate(x._capacity);
            _size = x._size;
            _capacity = x._capacity;
            for (size_type i = 0; i < x._size; i++)
                _base[i] = x._base[i];
        }

        ~vector()
        {
            free_base();
        }

        vector &operator=(const vector &x)
        {
            if (this == &x)
                return (*this);

            free_base();
            _alloc = x._alloc;
            _base = _alloc.allocate(x._capacity);
            _capacity = x._capacity;
            _size = x._size;
            for (size_type i = 0; i < x._size; i++)
                _base[i] = x._base[i];
            return (*this);
        }

        /**
         * @param n _capacity가 n보다 작으면 _capacity를 n으로 확장한다.
         */
        void reserve(size_type n)
        {
            if (n <= _capacity)
                return;

            pointer _new_base = _alloc.allocate(n);
            for (size_type i = 0; i < _size; i++)
                _new_base[i] = _base[i];
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(&_base[i]);
            _alloc.deallocate(_base, _capacity);
            _base = _new_base;
            _capacity = n;
        }

        void clear()
        {
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(&_base[i]);
            _size = 0;
        }

        void push_back(const value_type &val)
        {
            if (_size == _capacity)
                reserve(_capacity == 0 ? 1 : _capacity * 2);
            _base[_size++] = val;
        }

        void pop_back()
        {
            if (_size == 0)
                return;
            _alloc.destroy(&_base[--_size]);
        }

        template <class InputIterator>
        void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL)
        {
            clear();
            reserve(_distance(first, last));
            for (InputIterator it = first; it != last; it++)
                push_back(*it);
        }

        void assign(size_type n, const value_type &val)
        {
            clear();
            reserve(n);
            for (size_type i = 0; i < n; i++)
                push_back(val);
        }

        reference at(size_type n)
        {
            if (n >= _size)
                throw std::out_of_range("vector");
            return _base[n];
        }

        const_reference at(size_type n) const
        {
            if (n >= _size)
                throw std::out_of_range("vector");
            return _base[n];
        }

        iterator insert(iterator position, const value_type &val)
        {
            size_type n = position - begin();
            if (_size == _capacity)
                reserve(_capacity == 0 ? 1 : _capacity * 2);
            for (size_type i = _size; i > n; i--)
                _base[i] = _base[i - 1];
            _base[n] = val;
            _size++;
            return (begin() + n);
        }

        void insert(iterator position, size_type n, const value_type &val)
        {
            size_type pos = position - begin();
            if (_size + n > _capacity)
                reserve(_size + n);
            for (size_type i = _size + n - 1; i >= pos + n; i--)
                _base[i] = _base[i - n];
            for (size_type i = pos; i < pos + n; i++)
                _base[i] = val;
            _size += n;
        }

        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL)
        {
            size_type pos = position - begin();
            size_type n = _distance(first, last);
            if (_size + n > _capacity)
                reserve(_size + n);
            for (size_type i = _size + n - 1; i >= pos + n; i--)
                _base[i] = _base[i - n];
            for (size_type i = pos; i < pos + n; i++)
                _base[i] = *first++;
            _size += n;
        }

        iterator erase(iterator position)
        {
            size_type n = position - begin();
            for (size_type i = n; i < _size - 1; i++)
                _base[i] = _base[i + 1];
            _alloc.destroy(&_base[--_size]);
            return (begin() + n);
        }

        iterator erase(iterator first, iterator last)
        {
            size_type n = first - begin();
            size_type m = last - begin();
            for (size_type i = n; i < _size - (m - n); i++)
                _base[i] = _base[i + (m - n)];
            for (size_type i = 0; i < m - n; i++)
                _alloc.destroy(&_base[--_size]);
            return (begin() + n);
        }

        void resize(size_type n, value_type val = value_type())
        {
            if (n < _size)
            {
                for (size_type i = n; i < _size; i++)
                    _alloc.destroy(&_base[i]);
                _size = n;
            }
            else if (n > _size)
            {
                if (n > _capacity)
                    reserve(n);
                for (size_type i = _size; i < n; i++)
                    _base[i] = val;
                _size = n;
            }
        }

        void swap(vector &x)
        {
            this->_swap(_base, x._base);
            this->_swap(_size, x._size);
            this->_swap(_capacity, x._capacity);
            this->_swap(_alloc, x._alloc);
        }

        iterator begin()
        {
            return iterator(_base);
        }
        iterator end()
        {
            return iterator(_base + _size);
        }
        const_iterator begin() const
        {
            return const_iterator(_base);
        }
        const_iterator end() const
        {
            return const_iterator(_base + _size);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }
        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }
        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(end());
        }
        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(rend());
        }

        reference front()
        {
            return _base[0];
        }
        reference back()
        {
            return _base[_size - 1];
        }
        const_reference front() const
        {
            return _base[0];
        }
        const_reference back() const
        {
            return _base[_size - 1];
        }

        allocator_type get_allocator() const
        {
            return _alloc;
        }
        size_type size() const
        {
            return _size;
        }
        size_type max_size() const
        {
            return _alloc.max_size();
        }
        bool empty() const
        {
            return _size == 0;
        }
        size_type capacity() const
        {
            return _capacity;
        }

        reference operator[](size_type n)
        {
            return _base[n];
        }
        const_reference operator[](size_type n) const
        {
            return _base[n];
        }
    };

    template <class T, class Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(lhs > rhs);
    }

    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return rhs < lhs;
    }

    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(lhs < rhs);
    }

    template <class T, class Alloc>
    void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
    {
        x.swap(y);
    }

};

#endif
