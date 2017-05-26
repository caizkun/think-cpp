// Test protected members and methods
//
// Summary:
// 1. Upcasting: converting a object, reference, or pointer of the drived class into an object, reference, or pointer of the base class
//
// Test Output:
//    0


#include <iostream>

using namespace std;


enum note { middleC, Csharp, Cflat };


// base class
class instrument {
public:
    void play(note n) const {
        cout << n << endl;
    }
};


// derived class
class wind : public instrument {};


void tune(instrument &i) {
    i.play(middleC);
}


int main() {
    wind flute;
    tune(flute);    // upcasting
}





