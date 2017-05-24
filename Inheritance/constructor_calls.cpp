// Test the order of constructor & destructor calls in the inheritance hierarchy
//
// Summary:
// 1. Constructor calls: from the most based class down to the derived class
// 2. Destructor calls: in exactly the reverse order
// 3. the order of constructor calls are not affected by the order of the calls in the constructor initializer list
//
// Test Output:
//    Base1 constructor
//    Member1 constructor
//    Member2 constructor
//    Derived1 constructor
//    Member3 constructor
//    Member4 constructor
//    Derived2 constructor
//    Derived2 destructor
//    Member4 destructor
//    Member3 destructor
//    Derived1 destructor
//    Member2 destructor
//    Member1 destructor
//    Base1 destructor


#include <iostream>

using namespace std;

// define multiple classes
#define CLASS(ID) class ID { \
public: \
    ID(int) { cout << #ID " constructor" << endl; } \
    ~ID() { cout << #ID " destructor" << endl; } \
};

CLASS(Base1);
CLASS(Member1);
CLASS(Member2);
CLASS(Member3);
CLASS(Member4);

// derived level 1
class Derived1 : public Base1 {
public:
    Derived1(int) : m2(1), m1(2), Base1(3) {
        cout << "Derived1 constructor" << endl;
    }
    ~Derived1() {
        cout << "Derived1 destructor" << endl;
    }
private:
    Member1 m1;
    Member2 m2;
};

// derived level 2
class Derived2 : public Derived1 {
public:
    Derived2() : m3(1), Derived1(2), m4(3) {
        cout << "Derived2 constructor" << endl;
    }
    ~Derived2() {
        cout << "Derived2 destructor" << endl;
    }
private:
    Member3 m3;
    Member4 m4;
};


int main() {
    Derived2 d2;
    return 0;
}
