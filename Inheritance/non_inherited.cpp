// Test functions that do not automatically inherit
//
// Summary:
// Before C++11
// 1. Constructors and destructor do not inherit
// 2. The operator = does not inherit
// 3. If they are not explicitly defined or overriden, they would be synthesized by the compiler
//
// C++11:
// The default constructor, copy constructor, destructor, and operator = are inherited!
//
// Test Output:
//    Root()
//    Root(Root &)
//    Root::operator=()
//    Root::operator Other()
//    ~Root()
//    ~Root()


#include <iostream>

using namespace std;


// base class
class Root {
public:
    Root() {
        cout << "Root()" << endl;
    }
    
    Root(Root &) {
        cout << "Root(Root &)" << endl;
    }
    
    Root(int) {
        cout << "Root(int)" << endl;
    }
    
    Root & operator=(const Root &) {
        cout << "Root::operator=()" << endl;
        return *this;
    }
    
    class Other {};
    
    operator Other() const {
        cout << "Root::operator Other()" << endl;
        return Other();
    }
    
    ~Root() {
        cout << "~Root()" << endl;
    }
};


// derived class
class Derived : public Root {};


// function to test type-conversion
void f(Root::Other) {}


int main() {
    Derived d1;         // default constructor synthesized by the compiler
    Derived d2 = d1;    // copy constructor synthesized by the compiler
//    Derived d3(1);    // error: no int constructor (neither inherited nor synthesized)
    d1 = d2;            // Operator= not inherited but synthesized by the compiler
    f(d1);              // Type-conversion is inherited
    
    return 0;
}


