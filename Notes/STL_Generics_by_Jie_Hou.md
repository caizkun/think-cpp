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
* iterator_traits

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
class rb_tree {
    ...
};
```

### set & multiset
* sorted associative container with key = data (multiset allows duplication)
* implemented using rb_tree
* provides const iterator, which prohibits modifying key
```Cpp
template <class Key, 
          class Compare = less<int>, 
          class Alloc = alloc>
class set {
    ...
};
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
class map {
    ...
};
```

## Adapters
### queue
* first in first out (no iterator)
* implemented using deque (or list)

### stack
* first in last out (no iterator)
* implemented using deque (or list, or vector)



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


