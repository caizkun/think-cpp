// Test simple variadic template
//
// Summary:
// 1. Variadic template can process any number of arguments recursively
// 2. Pay attention to the "..."
// 2. Remember to create a stop criteion using specialization (below is print_any())

// Output:
//      hello
//      2
//      101

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

void print_any() {}

template<typename T, typename... Types>
void print_any(const T& x, const Types&... args) {
    cout << x << endl;
    //cout << "remaining num of args = " << sizeof...(args) << endl;
    print_any(args...);
}

int main() {
    print_any("hello", 2, bitset<3>(101));
    return 0;
}
