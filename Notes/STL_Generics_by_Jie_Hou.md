Notes taken from [STL and Generic Programming by Jie Hou](https://boolan.com/course/10095)

## STL components:  
* Containers
* Allocators
* Algorithms
* Iterators
* Adapters
* Functors

## Containers
### list
* doubly-linked (and round) list

### vector
* continous memory and resizable  
* memory increases by reallocating another continuous memory of twice large,
  copy-constructing items to new locations, and destructing the copied items  

### array
* continuous memory and fixed size
* no custom constructor or destructor

### forward_list
* singly-linked list

### deque
* buffer-wise continuous memory and resizeable on both ends

### rb_tree (not exposed by STL)
* reb-black tree, aka balanced binary search tree
* two basic methods: insert_unique(x), insert_equal(x)
* used to implement map, multimap, set, multiset
```Cpp
template <class Key,
          class Value,
          class KeyOfValue,
          class Compare,
          class Alloc = alloc>
class rb_tree;
```

### set & multiset
* sorted associative container with key = data (multiset allows duplication)
* implemented using rb_tree
* provides const iterator, which prohibits modifying key
```Cpp
template <class Key, 
          class Compare = less<int>, 
          class Alloc = alloc>
class set;
```
### map & multimap
* sorted associative container with value = `pair<const key, data>` (multiset allows duplication)
* implemented using rb_tree
* provides iterator, allowing data to be modified, but not key (declared as const) 
```Cpp
template <class Key, 
          class T,
          class Compare = less<Key>, 
          class Alloc = alloc>
class map;
```

### hashtable (not exposed by STL)
* unordered associative container
* hash_function(key) % bucket_size
* resolving collision: separate chaining using linked list
* rehash when num_elements exceeds bucket_size
* used to implemented unordered_set, unordered_multiset, unordered_map, unordered_multimap
```Cpp
template <class Value,
          class Key,
          class HashFcn,
          class ExtractKey,
          class EqualKey,
          class Alloc = alloc>
class hashtable;
```

### unordered_set & unordered_multiset
* unordered associative container with key = data 
```Cpp
template <typename T,
          typename Hash = hash<T>,
          typename EqPred = equal_to<T>,
          typename Allocator = allocator<T> >
class unordered_set;
```

### unordered_map & unordered_multimap
* unordered associative container with value = pair<const key, data>
```Cpp
template <typename Key,
          typename T,
          typename Hash = hash<T>,
          typename EqPred = equal_to<T>,
          typename Allocator = allocator<pair<const Key, T> >
class unordered_map;
```

## Adapters
### container adapters
#### queue
* first in first out (no iterator)
* implemented using deque (or list)

#### stack
* first in last out (no iterator)
* implemented using deque (or list, or vector)

### iterator adapters


### functor adapters


## Iterators
### iterator_traits
```Cpp
template <typename T>
class iterator_traits {
    typedef random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef ptrdiff_t different_type;
};
```
### iterator_category
```Cpp
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};
```

### Algorithms 
Patterns (function templates):
```Cpp
template <typename Iterator, ...>
return_type some_algorithm(Iterator first, Iterator last, ...) {}
```
```Cpp
template <typename Iterator, typename Compare, ...>
return_type some_algorithm(Iterator first, Iterator last, Compare comp, ...) {}
```

### Functors
Functors interact with algorithms and are typically used as comparator classes. In STL convention, functors inherit from either `unary_function` or `binary_function`.
```Cpp
template <class Arg, class Result>
struct unary_function {
    typedef Arg argument_type;
    typedef Result result_type;
};

template <class Arg1, class Arg2, class Result>
struct binary_function {
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argument_type;
    typedef Result result_type;
};
```
Examples:
```Cpp
template <class T>
class plus : public binary_function<T, T, T> {
    T operator()(const T& x, const T& y) const {
        return x + y;
    }
};

template <class T>
bool less : public binary_function<T, T, bool> {
    bool operator()(const T& x, const T& y) const {
        return x < y;
    }
};
```

### Misc
#### tuple (C++11, variadic template)
```Cpp
template <typename... Values>
class tuple;

tempalte<>
class tuple<> {};

template <typename Head, typename... Tail>
class tuple<Head, Tail...> : private tuple<Tail...> {
private:
    typedef tuple<Tail...> inherited;
public:
    tuple() {}
    tuple(Head v, Tail... vtail) : m_head(v), inherited(vtail...) {}
    
    typename Head::type head() { return m_head; }
    inherited& tail() { return *this; }
protected:
    Head m_head;
};
```

#### type traits (to serve Algorithms)
[#include <type_traits>](http://www.cplusplus.com/reference/type_traits/)
Simple example: `is_void`
```Cpp
template <typename _Tp>
struct remove_const {
    typedef _Tp type;
};

template <typename _Tp>
struct remove_const<_Tp const> {
    typedef _Tp type;
};

template <typename _Tp>
struct remove_volatile {
    typedef _Tp type;
};

template <typename _Tp>
struct remove_volatile<_Tp volatile> {
    typedef _Tp type;
};

template <typename _Tp>
struct remove_cv {
    typedef typename remove_const< typename remove_volatile<_Tp>::type >::type type;
};

template <typename>
struct __is_void_helper : public false_type {};

tempalte <typename>
struct __is_void_helper<void> : public true_type {};

// main
template <typename _Tp>
struct is_void : public __is_void_helper< typename remove_cv<_Tp>::type >::type
```
The implementation of more complicated type traits usually involves the power of the compiler under the *programming* hood.

