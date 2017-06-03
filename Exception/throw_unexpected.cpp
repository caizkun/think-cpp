// Test throwing an exception that is unexpected
//
// Summary:
// 1. Special function "unexpected()" would be called if an exception thrown is not in the specialization list
// 2. Use the special function "set_unexpected()" to customize the "unexpected()" function
//
//
// Test Output:
//    up caught
//    fit caught
//    unexpected exception thrown


#include <iostream>
#include <exception>
#include <cstdlib>
#include <string>

using namespace std;


class up {};
class fit {};
void g();


void f(int i) throw(up, fit) {
    switch(i) {
        case 1: throw up();     // exit from throw
        case 2: throw fit();    // exit from throw
    }
    g();        // can throw an exception that is not in the specialization list
}


//void g() {}   // versio 1, no exception thrown
void g() {      // version 2, can throw built-in types
    throw 47;
}


void my_unexpected() {
    cout << "unexpected exception thrown" << endl;
    exit(1);
}


int main() {
    set_unexpected(my_unexpected);
    
    for (int i = 1; i <= 3; ++i) {
        try {
            f(i);
        } catch(up) {
            cout << "up caught" << endl;
        } catch(fit) {
            cout << "fit caught" << endl;
        } catch(...) {
            cout << "unknown caughted" << endl;
        }
    }
    
    return 0;
}
