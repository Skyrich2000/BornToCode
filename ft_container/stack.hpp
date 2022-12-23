#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T>

              >
    class stack
    {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;

        explicit stack(const container_type &ctnr = container_type()) : c(ctnr) {}

        /**
         * 공식문서에도 소멸자가 없음
         */
        // ~stack() {}

        bool empty() const
        {
            return c.empty();
        }

        size_type size() const
        {
            return c.size();
        }

        value_type &top()
        {
            return c.back();
        }

        const value_type &top() const
        {
            return c.back();
        }

        void push(const value_type &val)
        {
            c.push_back(val);
        }

        void pop()
        {
            c.pop_back();
        }

        /**
         * 실제 stack 에서도 c 에 접근하기 위해서 friend 로 선언되어 있음
         */
        friend bool operator==(const stack &lhs, const stack &rhs)
        {
            return lhs.c == rhs.c;
        }

        /**
         * 실제 stack 에서도 c 에 접근하기 위해서 friend 로 선언되어 있음
         */
        friend bool operator<(const stack &lhs, const stack &rhs)
        {
            return lhs.c < rhs.c;
        }

    protected: // private 로 바꾸고 테스트하면 터질지도??
        /**
         * 실제 stack 에서도 protected 로 선언되어 있음
         */
        container_type c;
    };

    template <class T, class Container>
    inline bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T, class Container>
    inline bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return !(rhs < lhs);
    }

    template <class T, class Container>
    inline bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return rhs < lhs;
    }

    template <class T, class Container>
    inline bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return !(lhs < rhs);
    }
};

#endif