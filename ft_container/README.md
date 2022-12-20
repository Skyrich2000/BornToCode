## 기본 개념

## Utiliy.hpp

1. is_integral, enable_if 이해

- cpp 가 멍청해서 overload 를 똑바로 못함 size_type(integral) 과 InputIterator 를 구분할 수 없음
- enable_if 를 통해 InputIterator 가 아닌 경우에만 호출되도록 함
- 템플릿 특수화

```cpp
    void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = nullptr);
    void assign(size_type n, const value_type &val);
```

2. equal , lexicographical_compare 구현

- 둘다 레퍼런스에서 구현해놨다 개꿀티비

3. pair 구현

```cpp
#include <utility>  // <- 여기서 직접 봐도 됨 단, cpp 98 문법 조심

// 상세 구현 스펙 https://en.cppreference.com/w/cpp/utility/pair

// 구현해야할 Member functions
// (constructor) : constructs new pair (public member function) (기본, 복사 생성자 등)
// operator= : assigns the contents (public member function)

// 구현해야할 Non-member functions
// mair_pair : 근데 이거 이미 구현체 나와있음
// operator==
// operator!=
// operator<
// operator<=
// operator>
// operator>=
```

## Iterator.hpp

- 개념
  - random access iterator (배열 형식이라서 어디든 접근 가능 O(1))
  - bidirectional iterator (양방향 iterator, 연결 리스트 같은거 접근할떄 씀 tree 구조체 등 O(n) or O(nlogn))

1. iterator_traits

- iterator 의 상태(특성)를 나타내는 구조체!! 그냥 정의만 해주는거임

```cpp
// https://legacy.cplusplus.com/reference/iterator/iterator_traits/?kw=iterator_traits
// Member types 구현할것

typedef typename _Iter::difference_type difference_type; // iterator 간의 거리
typedef typename _Iter::value_type value_type; // iterator 가 가리키는 값의 타입
typedef typename _Iter::pointer pointer; // iterator 가 가리키는 값의 포인터 타입
typedef typename _Iter::reference reference; // iterator 가 가리키는 값의 레퍼런스 타입
typedef typename _Iter::iterator_category iterator_category; // random, bidirectional 구분

// typename 쓰는이유 중첩 타입에서 이게 변수인지 타입인지 구분하기 위해서
```

2. iterator 구현

```cpp
// https://legacy.cplusplus.com/reference/iterator/iterator/?kw=iterator
// 구현체 나와잇음
// 사실 내용이 없음
```

3. reverse_iterator 구현

- https://legacy.cplusplus.com/reference/iterator/reverse_iterator/?kw=reverse_iterator
- 내부적으로 원본 iterator 복사본을 들고 있어야함

```cpp
// 구현해야할 Member functions
// (constructor) - Constructs reverse_iterator object (public member function )
// base - Return base iterator (public member function )
// operator* - Dereference iterator (public member function )
// operator+ - Addition operator (public member function )
// operator++ - Increment iterator position (public member function )
// operator+= - Advance iterator (public member function )
// operator- - Subtraction operator (public member function )
// operator-- - Decrease iterator position (public member function )
// operator-= - Retrocede iterator (public member function )
// operator-> - Dereference iterator (public member function )
// operator[] - Dereference iterator with offset (public member function )

// https://legacy.cplusplus.com/reference/iterator/reverse_iterator/operators/
// template <class Iterator1, class Iterator2> 는 C++ 11 부터
// 구현해야할 Non-member functions
// operator==
// operator!=
// operator<
// operator<=
// operator>
// operator>=
// operator+
// operator-
```

4. random_access_iterator 구현

- 사실상 해주는건 포인터 연산을 wrap 해준것일뿐
- iterate utils 들 (begin, end) 등의 혜택을 받기 위해서 감싼것뿐이고 (알고리즘 적용을 가능하게 해주는것 뿐)
- 실제로는 거의 깡통에 가까움

- https://cplusplus.com/reference/iterator/
- 실제 구현체 의존 순서 (뇌피셜)

  - Forward -> Bidirectional -> Random Access

- iterator 의 base 가 되는 느낌이라고 생각하면 됨
- 그래서 실제로 reverse_iterator 와 스펙이 비슷함
  - 유일하게 차이점은 대입 연산이 가능 하다는 점!
  - reverse_iterator 는 대입 연산이 불가능함 (암묵적 생성이 불가능하기 때문!)

5. vector 구현

- 공식 스펙 https://en.cppreference.com/w/cpp/container/vector
- 그러나 vector 헤더에서 실제 구현을 보는것도 나쁘지 않음

- 생성자 스펙 : https://legacy.cplusplus.com/reference/vector/vector/vector/
- 구현할거 개많음...

- private 멤버 변수 는 사람마다 구현마다 다 다르다 근데 난 이렇게 구현할거임

```cpp
    private:
        pointer _base;
        size_type _size;
        size_type _capacity;
        allocator_type _alloc;
```

또는

```cpp
    private:
        pointer _start;
        pointer _finish;
        size_type _size;
        size_type _capacity;
        allocator_type _alloc;
```
