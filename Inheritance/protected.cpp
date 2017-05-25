// Test protected members and methods
//
// Summary:
// 1. "Protected" behaves like "private" except that when inherited, the protected members and methods are available to the derived class.
//
// Test Output:
//    b.value() = 0
//    d.value() = 5


#include <iostream>

using namespace std;


// base class
class Base {
public:
    Base(int n = 0) : i(n) {}
    
    int value() const {
        return i;
    }

protected:
    int read() const {
        return i;
    }
    
    void set(int n) {
        i = n;
    }

private:
    int i;
};


// derived class
class Derived : public Base {
public:
    Derived(int n = 0) : i(n) {}
    
    void change(int x) {
        set(x);
    }
private:
    int i;
};


int main() {
    Base b;
    cout << "b.value() = " << b.value() << endl;
//    cout << "b.read() = " << b.read() << endl;    // Error: read() is protected in Base
    
    Derived d;
    d.change(5);
    cout << "d.value() = " << d.value() << endl;
    return 0;
}







