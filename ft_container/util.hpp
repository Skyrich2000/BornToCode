#ifndef FT_UTIL_HPP
#define FT_UTIL_HPP

namespace ft
{
    template <bool Bool, class T = void>
    struct enable_if
    {
    };
    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    template <class T>
    struct is_integral
    {
        static const bool value = false;
    };
    template <>
    struct is_integral<bool>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<wchar_t>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<char>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<signed char>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned char>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<short>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned short>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<long>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned long>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<long long>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned long long>
    {
        static const bool value = true;
    };

    /**
     * equal - test whether the elements in two ranges are equal
     *
     * @see https://en.cppreference.com/w/cpp/algorithm/equal
     * @see https://legacy.cplusplus.com/reference/algorithm/equal/
     */
    template <class InputIt1, class InputIt2>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2)) // or: if (!pred(*first1,*first2)), for version 2
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    /**
     * lexicographical_compare - compare lexicographically two ranges
     *
     * @remarks
     * 2개가 길이가 다를 수 있음!
     *
     * @see https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
     * @see https://legacy.cplusplus.com/reference/algorithm/lexicographical_compare/
     */
    template <class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    /**
     * @see https://en.cppreference.com/w/cpp/utility/pair
     * @see https://legacy.cplusplus.com/reference/utility/pair/?kw=pair
     */
    template <class T1, class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        T1 first;
        T2 second;

        pair() : first(), second() {} // 기본 생성자

        pair(const T1 &x, const T2 &y) : first(x), second(y) {} // 생성자

        template <class U1, class U2>
        pair(const pair<U1, U2> &p) : first(p.first), second(p.second) {} // 복사생성자

        ~pair() {} // 소멸자

        pair &operator=(const pair &other)
        {
            first = other.first;
            second = other.second;
            return *this;
        }
    };

    template <class T1, class T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }
    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(lhs == rhs);
    }
    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (lhs.first < rhs.first || ((rhs.first == lhs.first) && lhs.second < rhs.second));
    }
    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (!(rhs < lhs));
    }
    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (rhs < lhs);
    }
    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (!(lhs < rhs));
    }

    /**
     *  make_pair - create a pair object
     *
     * @see https://legacy.cplusplus.com/reference/utility/make_pair/
     */
    template <class T1, class T2>
    pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return (pair<T1, T2>(x, y));
    }

    /**
     * swap
     *
     * @remarks
     * 그냥 편해보여서 만들어둠
     */
    template <class T>
    void swap(T &a, T &b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    }
}

#endif
