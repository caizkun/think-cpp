// Move semantics
//
// Summary:
// 1. Lvalue vs Rvalue: 
//      Lvalue is usually an object that has identifiable address in the memory
//      Rvalue is an object that is not a Lvalue. E.g. a+5 
//
// 4. Move semantics make use of the rvalue reference of a temporary obj
// to avoid unnecessary deep copy.
//
// 3. Move semantics mainly includes:
//    - std::move casts its argument into a rvalue.
//    - move constructor and move assignment operator take a rvalue reference
//      as parameter and can be overloaded to move data efficiently
//    - function overloading distinguishes parameters passed as a lvalue or rvalue
//    - from our test, we can see that nowadays the compilers is so smart that
//      it usually handles passing data by rvalue reference silently 
//
//
// Test Ouput:
//    Called constructor from a char array
//   
//    Called copy constuctor
//   
//    Print nothing (see comments in the code)
//   
//    Called copy constuctor
//    hello
//    Called move constructor
//   
//    hellohello
//    Called move constructor
//   
//    Called move constructor
//    hello
//    Called move constructor
//    s2.data becomes a nullptr


#include <iostream>
#include "string.h"

using namespace std;

class MyString {
public:
    char* data;

    MyString() {
        data = nullptr;
    }

    // constructor from a char array
    MyString(const char* p) {
        size_t size = strlen(p) + 1;
        data = new char[size];
        memcpy(data, p, size);
        cout << "Called constructor from a char array" << endl;
    }
    
    // copy constructor
    MyString(const MyString& another) {
        size_t size = strlen(another.data) + 1;
        data = new char[size];
        memcpy(data, another.data, size);
        cout << "Called copy constuctor" << endl;
    } 

    // copy assignment operator using the copy-swap idiom
    MyString& operator=(MyString another) {
        swap(data, another.data);
        cout << "Called copy assignment operator" << endl;
        return *this;
    }

    // Move constructor using Rvalue reference
    // Redirect another to avoid destr. of another deleting the moved data
    MyString(MyString&& another) {
        data = another.data;
        another.data = nullptr;     
        cout << "Called move constructor" << endl;
    }

//    // Move assignment operator
//    MyString& operator=(MyString&& another) {
//        swap(data, another.data);
//        another.data = nullptr;
//        cout << "Called move assignment operator" << endl;
//        return *this;
//    }

    MyString operator+(const MyString& rhs) {
        MyString str;
        size_t data_size = strlen(data);
        size_t rhs_size = strlen(rhs.data);
        str.data = new char[data_size + rhs_size + 1];
        int i = 0;
        for (int j = 0; j < data_size; ++j) {
            str.data[i++] = data[j];
        }
        for (int j = 0; j < rhs_size; ++j) {
            str.data[i++] = rhs.data[j];
        }
        str.data[i] = '\0';
        return str;
    }

    // destructor
    ~MyString() {
        delete[] data;
    }
};


// A function with a MyString passed by value
// will invoke
MyString foo(MyString s) {
    size_t size = strlen(s.data) + 1;
    for (int i = 0; i < size; ++i) {
        cout << s.data[i];
    }
    cout << endl;
    return s;
}


int main() {
    char p[] = "hello";

    // call constr from a char array
    MyString s1(p);
    cout << endl;

    // call copy constructor
    MyString s2(s1);
    cout << endl;

    // This is supposed to call move constructor but the test shows no.
    // It is likely that the complier has been able to handle rvalue
    // reference silently
    MyString s3{s1 + s2};
    MyString s4{MyString()};
    cout << "Print nothing (see comments in the code)" << endl;
    cout << endl;

    // call copy constructor when the argument is passed
    // but you can see when the func returns, move constr is called 
    // intstead of copy constr. This confirms the complier optimizes 
    // moving data silently
    foo(s2);       
    cout << endl;

    // This is supposed to call move constructor when passing the arg
    // but the compiler again handles it silently
    foo(s1 + s2); 
    cout << endl;

    // to explicitly use rvalue reference and move data, use std::move
    foo(move(s2));
    if (s2.data == nullptr) {
        cout << "s2.data becomes a nullptr" << endl;
    }

    return 0;
}
