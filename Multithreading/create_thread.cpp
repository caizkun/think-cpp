/*
 * Summary:
 * 1. Instantiate a thread using std::thread(func, args...);
 * 2. The lift cycle of a thread: created when entering the entry function, destroyed when returned; (dont know about thread pool right now)
 * 3. A thread must be joined (if joinable) or detached before destroyed; otherwise terminate() would be called.
 *
 */

#include <iostream>
#include <string>
#include <thread>

using namespace std;


void sayHello(string message) {
    cout << endl;
    cout << message << endl;
    cout << "This is the entry of a new thread with tid " << this_thread::get_id() << endl;
    
    // do some stuff
    
    cout << "This thread will be gone after return!" << endl;
}

int main() {
    // instantiate a thread
    thread t1(sayHello, "Hello Multithreading");

    // do something in the main thread
    cout << "Hello, I am the main thread!" << endl;

    // the main thread waits for thread t1 to finish and join it
    if (t1.joinable()) {
        t1.join();
    }
    cout << "\nthread joined successfully!" << endl;

    return 0;
}






