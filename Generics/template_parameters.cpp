// Test template parameters
// Below is an interesting solution of computing the fibonacci numbers using template paramter
//
// Summary:
// 1. "tempate<typename T>" is commonly used for creating template class or function
// 2. Besides, one can also pass parameters from a template when creating template classes,
//    e.g. below template<int N> is passed to create struct fib.
// 3. One can instantiate the class by using fib<k>, where k comforms to the parameter type
// 4. Some example usage is that one calls bitset<n> from STL to initiate an bitset of size n;
//
// 5. As for the fibonacci algorithm, the key idea is using memorization to avoid duplicated computing.
//    Here this algorithm uses template to create a bunch of classes, each of which contains an static member result. Once created, the class persists and the result variable serves as memorization.
//
//
// Test Output:
//      Fib(10) = 55



// this is a fantastic solution from ... (god knows somewhere)
#include <iostream>

template<int N> struct fib {
    static const int result = fib<N-1>::result + fib<N-2>::result;
};

template<> struct fib<0> {
    static const int result = 0;
};

template<> struct fib<1> {
    static const int result = 1;
};

int main(int ac, char *av[])
{
    const int M = 10;
    std::cout << "Fib(10) = " << fib<M>::result << std::endl;
    return 0;
}
