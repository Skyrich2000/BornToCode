#ifndef FT_RANDOM_ACCESS_ITERATOR_HPP
#define FT_RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
    template <typename T>
    class random_access_iterator
    {
    public:
        typedef typename ft::iterator_traits<T *>::pointer pointer;
        typedef typename ft::iterator_traits<pointer>::value_type value_type;
        typedef typename ft::iterator_traits<pointer>::reference reference;
        typedef typename ft::iterator_traits<pointer>::difference_type difference_type;
        typedef std::random_access_iterator_tag iterator_category;

        random_access_iterator(void) : _p(NULL) {}

        random_access_iterator(pointer p) : _p(p) {}

        random_access_iterator(const random_access_iterator &other) : _p(other._p) {}

        random_access_iterator &operator=(const random_access_iterator &other)
        {
            if (this == &other)
                return (*this);
            this->_p = other._p;
            return (*this);
        }

        virtual ~random_access_iterator() {}

        pointer base() const
        {
            return (this->_p);
        }

        // ----------------------------------------
        // operator* 연산
        // ----------------------------------------

        reference operator*()
        {
            return (*(this->_p));
        }

        const reference operator*() const
        {
            return (*(this->_p));
        }

        // ----------------------------------------
        // operator-> 연산
        // ----------------------------------------

        pointer operator->()
        {
            return (_p);
        }

        const pointer operator->() const
        {
            return (_p);
        }

        // ----------------------------------------
        // operator[] 연산
        // ----------------------------------------

        reference operator[](difference_type n)
        {
            return (*(operator+(n)));
        }

        const reference operator[](difference_type n) const
        {
            return (*(operator+(n)));
        }

        // ----------------------------------------
        // operator+ 연산
        // ----------------------------------------

        random_access_iterator operator+(difference_type n)
        {
            return (_p + n);
        }

        /**
         * @remarks
         * c++ 98 스펙에 const 가 있는지 확실하지 않으나, 일단 const 스펙을 추가합니다.
         */
        const random_access_iterator operator+(difference_type n) const
        {
            return (_p + n);
        }

        // ----------------------------------------
        // &operator++ 연산
        // ----------------------------------------

        random_access_iterator &operator++()
        {
            _p++;
            return (*this);
        }

        const random_access_iterator &operator++() const
        {
            _p++;
            return (*this);
        }

        // ----------------------------------------
        // operator++(int) 연산
        // ----------------------------------------

        random_access_iterator operator++(int)
        {
            random_access_iterator n(*this);
            ++(*this);
            return (n);
        }

        const random_access_iterator operator++(int) const
        {
            random_access_iterator n(*this);
            ++(*this);
            return (n);
        }

        // ----------------------------------------
        // &operator+= 연산
        // ----------------------------------------

        random_access_iterator &operator+=(difference_type n)
        {
            _p += n;
            return (*this);
        }

        const random_access_iterator &operator+=(difference_type n) const
        {
            _p += n;
            return (*this);
        }

        // ----------------------------------------
        // operator- 연산
        // ----------------------------------------

        random_access_iterator operator-(difference_type n)
        {
            return (_p - n);
        }

        const random_access_iterator operator-(difference_type n) const
        {
            return (_p - n);
        }

        // ----------------------------------------
        // &operator-- 연산
        // ----------------------------------------

        random_access_iterator &operator--()
        {
            _p--;
            return (*this);
        }

        const random_access_iterator &operator--() const
        {
            _p--;
            return (*this);
        }

        // ----------------------------------------
        // operator--(int) 연산
        // ----------------------------------------

        random_access_iterator operator--(int)
        {
            random_access_iterator n(*this);
            --(*this);
            return (n);
        }

        const random_access_iterator operator--(int) const
        {
            random_access_iterator n(*this);
            --(*this);
            return (n);
        }

        // ----------------------------------------
        // &operator-= 연산
        // ----------------------------------------

        random_access_iterator &operator-=(difference_type n)
        {
            _p -= n;
            return (*this);
        }

        const random_access_iterator &operator-=(difference_type n) const
        {
            _p -= n;
            return (*this);
        }

        // TODO: 야매로 구현한 부분. 확인 필요.
        operator random_access_iterator<const T>() const
        {
            return (random_access_iterator<const T>(this->_p));
        }

    private:
        pointer _p;
    };

    // ----------------------------------------
    // operator== 연산
    // ----------------------------------------

    template <class Iterator>
    bool operator==(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class LIterator, class RIterator>
    bool operator==(const random_access_iterator<LIterator> &lhs, const random_access_iterator<RIterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    // ----------------------------------------
    // operator!= 연산
    // ----------------------------------------

    template <class Iterator>
    bool operator!=(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <class LIterator, class RIterator>
    bool operator!=(const random_access_iterator<LIterator> &lhs, const random_access_iterator<RIterator> &rhs)
    {
        return (lhs.base() != rhs.base());
    }

    // ----------------------------------------
    // operator< 연산
    // ----------------------------------------

    template <class Iterator>
    bool operator<(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <class LIterator, class RIterator>
    bool operator<(const random_access_iterator<LIterator> &lhs, const random_access_iterator<RIterator> &rhs)
    {
        return (lhs.base() < rhs.base());
    }

    // ----------------------------------------
    // operator<= 연산
    // ----------------------------------------

    template <class Iterator>
    bool operator<=(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template <class LIterator, class RIterator>
    bool operator<=(const random_access_iterator<LIterator> &lhs, const random_access_iterator<RIterator> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    // ----------------------------------------
    // operator> 연산
    // ----------------------------------------

    template <class Iterator>
    bool operator>(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <class LIterator, class RIterator>
    bool operator>(const random_access_iterator<LIterator> &lhs, const random_access_iterator<RIterator> &rhs)
    {
        return (lhs.base() > rhs.base());
    }

    // ----------------------------------------
    // operator>= 연산
    // ----------------------------------------

    template <class Iterator>
    bool operator>=(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template <class LIterator, class RIterator>
    bool operator>=(const random_access_iterator<LIterator> &lhs, const random_access_iterator<RIterator> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    // ----------------------------------------
    // operator+ 연산
    // ----------------------------------------

    template <class Iterator>
    random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator>::difference_type n, const random_access_iterator<Iterator> &rhs)
    {
        return (rhs + n);
    }

    // ----------------------------------------
    // operator- 연산
    // ----------------------------------------

    template <class Iterator>
    typename random_access_iterator<Iterator>::difference_type operator-(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs)
    {
        return (lhs.base() - rhs.base());
    }

    template <class LIterator, class RIterator>
    typename random_access_iterator<LIterator>::difference_type operator-(const random_access_iterator<LIterator> &lhs, const random_access_iterator<RIterator> &rhs)
    {
        return (lhs.base() - rhs.base());
    }

};

#endif