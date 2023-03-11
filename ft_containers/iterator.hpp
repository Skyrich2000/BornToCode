#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

#include <type_traits>
#include <iterator> // std::random_access_iterator_tag
#include <cstddef>  // ptrdiff_t

namespace ft
{
    /**
     * @remarks
     * 여기는 Iterator 를 받는 iterator_traits 를 선언한다.
     * 예를들어 reverse_iterator 에서 사용한다.
     */
    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::iterator_category iterator_category;
    };

    /**
     * @remarks
     * 여기는 T 를 받는 iterator_traits 를 선언한다.
     * 예를들어 random_access_iterator 에서 사용한다.
     */
    template <class T>
    struct iterator_traits<T *>
    {
        typedef T *pointer;
        typedef T value_type;
        typedef T &reference;
        typedef ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <class T>
    struct iterator_traits<const T *>
    {
        typedef const T *pointer;
        typedef T value_type;
        typedef const T &reference;
        typedef ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
    struct iterator
    {
        typedef Pointer pointer;
        typedef T value_type;
        typedef Reference reference;
        typedef Distance difference_type;
        typedef Category iterator_category;
    };

    template <class Iterator>
    class reverse_iterator
    {
    public:
        typedef Iterator iterator_type;
        typedef typename iterator_traits<Iterator>::pointer pointer;
        typedef typename iterator_traits<Iterator>::value_type value_type;
        typedef typename iterator_traits<Iterator>::reference reference;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;
        typedef typename iterator_traits<Iterator>::iterator_category iterator_category;

        reverse_iterator() : _current() {}

        explicit reverse_iterator(iterator_type it) : _current(it) {}

        template <class U>
        reverse_iterator(const reverse_iterator<U> &rev_it) : _current(rev_it.base()) {}

        template <class U>
        reverse_iterator &operator=(const reverse_iterator<U> &other)
        {
            this->_current = other.base();
            return (*this);
        }

        virtual ~reverse_iterator() {}

        iterator_type base() const
        {
            return (_current);
        }

        /**
         * @remarks
         * iterator 랑 reverse_iterator 가 실제로 가리키고 있는것이 다름..! reverse_iterator는 이전것을 가리키고 있음
         */
        reference operator*()
        {
            Iterator temp = _current;
            return (*(--temp));
        }

        /**
         * @see https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator*
         */
        const reference operator*() const
        {
            Iterator temp = _current;
            return (*(--temp));
        }

        /**
         * c++ 98 에서는 const 가 없다
         * @see https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator_arith
         */
        reverse_iterator operator+(difference_type n) const
        {
            return (reverse_iterator(_current - n));
        }

        reverse_iterator &operator++()
        {
            --_current;
            return (*this);
        }

        reverse_iterator operator++(int)
        {
            reverse_iterator temp = *this;
            ++(*this);
            return (temp);
        }

        reverse_iterator &operator+=(difference_type n)
        {
            _current -= n;
            return (*this);
        }

        reverse_iterator operator-(difference_type n) const
        {
            return (reverse_iterator(_current + n));
        }

        reverse_iterator &operator--()
        {
            ++_current;
            return (*this);
        }

        reverse_iterator operator--(int)
        {
            reverse_iterator temp = *this;
            --(*this);
            return (temp);
        }

        reverse_iterator &operator-=(difference_type n)
        {
            _current += n;
            return (*this);
        }

        pointer operator->()
        {
            return &(operator*());
        }

        /**
         * @see https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator*
         */
        const pointer operator->() const
        {
            return &(operator*());
        }

        /**
         * c++ 98 에서는 const 가 없다
         * @see https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator_at
         */
        reference operator[](difference_type n) const
        {
            return (this->base()[-n - 1]);
        }

    private:
        iterator_type _current;
    };

    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    /**
     * 과제 요구 사항에 있진 않지만, list iterator 와 vector iterator 를 비교하기 위해
     */
    template <class LIterator, class RIterator>
    bool operator==(const reverse_iterator<LIterator> &lhs, const reverse_iterator<RIterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() != rhs.base());
    }

    /**
     * 과제 요구 사항에 있진 않지만, list iterator 와 vector iterator 를 비교하기 위해
     */
    template <class LIterator, class RIterator>
    bool operator!=(const reverse_iterator<LIterator> &lhs, const reverse_iterator<RIterator> &rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() > rhs.base());
    }

    /**
     * 과제 요구 사항에 있진 않지만, list iterator 와 vector iterator 를 비교하기 위해
     */
    template <class LIterator, class RIterator>
    bool operator<(const reverse_iterator<LIterator> &lhs, const reverse_iterator<RIterator> &rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    /**
     * 과제 요구 사항에 있진 않지만, list iterator 와 vector iterator 를 비교하기 위해
     */
    template <class LIterator, class RIterator>
    bool operator<=(const reverse_iterator<LIterator> &lhs, const reverse_iterator<RIterator> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() < rhs.base());
    }

    /**
     * 과제 요구 사항에 있진 않지만, list iterator 와 vector iterator 를 비교하기 위해
     */
    template <class LIterator, class RIterator>
    bool operator>(const reverse_iterator<LIterator> &lhs, const reverse_iterator<RIterator> &rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    /**
     * 과제 요구 사항에 있진 않지만, list iterator 와 vector iterator 를 비교하기 위해
     */
    template <class LIterator, class RIterator>
    bool operator>=(const reverse_iterator<LIterator> &lhs, const reverse_iterator<RIterator> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    /**
     * @see https://legacy.cplusplus.com/reference/iterator/reverse_iterator/operator_plus-free/
     */
    template <class Iter>
    reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &rev_it)
    {
        return (rev_it + n);
    }

    /**
     * @see https://legacy.cplusplus.com/reference/iterator/reverse_iterator/operator_minus-free/
     */
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (rhs.base() - lhs.base());
    }

    /**
     * 과제 요구 사항에 있진 않지만, list iterator 와 vector iterator 를 비교하기 위해
     */
    template <class LIterator, class RIterator>
    ptrdiff_t operator-(const reverse_iterator<LIterator> &lhs, const reverse_iterator<RIterator> &rhs)
    {
        return (rhs.base() - lhs.base());
    }
};

#endif
