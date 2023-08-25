/*
 * This lesson continues lesson 2. Our aim along the way as we progress through the lessons is to avoid
 * making copies of the Vector. If the Vector conatins a billion elements, making copy will be very expensive.
 * In lesson 2 we fixed the copy in lesson 1. This lesson shows another pitfall and how we can unwittingly trigger
 * another copy operation.
 */

#include <stdlib.h>
#include <iostream>
#include <memory>

using namespace std;

class Vector {
    public:

        Vector() {
            cout << "constructor" << endl;
        }

        Vector(const Vector& a) {
            cout << "copy constructor" << endl;
        }

        Vector& operator=(const Vector& a) {
            cout << "copy assignment" << endl;
            return *this;
        }

        Vector(Vector && a) {
            cout << "move constructor" << endl;
        }

        Vector& operator=(Vector && a) {
            cout << "move assignment" << endl;
            return *this;
        }

        ~Vector() {
            cout << "destructor" << endl;
        }
};

class A {
public:
    shared_ptr<Vector> x_;

    A(shared_ptr<Vector> a) : x_(a) {
        
    }

    Vector & x() {
        return *x_;
    }
};

int main() {
    auto p = make_shared<Vector>();
    A a{p};
    auto q = a.x(); // BAD: copy constructor triggered here!
    return 0;
}

/*
Output:
constructor
copy constructor
destructor
destructor
*/