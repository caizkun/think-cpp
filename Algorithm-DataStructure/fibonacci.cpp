// summary fibonacci

// this is a fantastic solution
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
