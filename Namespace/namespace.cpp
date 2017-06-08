// Test using namespace
//
// Summary:
// 1. Namespace encapsulates members and member functions to address name collisions.
// 2. Namespace is loaded with the keyword "using"
// 3. "Using namespace XXX" introduce the whole namespace; "Using XXX::Y" introduces a specific name within the namespace.
//
// Test Output:
//    V::f()
//    U::f()


#include <iostream>

using namespace std;

namespace U {
    void f() { cout << "U::f()" << endl; }
    void g() { cout << "U::g()" << endl; }
}

namespace V {
    void f() { cout << "V::f()" << endl; }
    void g() { cout << "V::g()" << endl; }
}


void func() {
    using namespace U;  // using directive
    using V::f;         // using declartion
    f();                // calls V::f()
    U::f();             // must fully qualify to call
}


int main() {
    func();
    
    return 0;
}
