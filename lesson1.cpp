#include <stdlib.h>
#include <iostream>

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
    Vector x;

    A(Vector & a) : x(a) {
        // the point of this code is to show that x(a) triggers a call to the Vector's
        // copy constructor. This means if we were using a std::vector, it would result in
        // copying of values of vector a to x which is O(n) operation.
        // the point being illustrated is that even though we avoided a copy of the vector by
        // passing it by reference to ctor of A, we could not avoid a copy when we "assigned"
        // a to x. In Java, there would have been no copy (only reference to the vector would be copied)

        // if we hadn't used & in the ctor, there would have been another call to the copy constructor.
    }
};

int main() {
    Vector a;
    A q{a}; // BAD: a copy of the Vector is triggered even though we are passing by reference because within A, we are making a copy.
    return 0;
}

/*
Output:
constructor
copy constructor
destructor
destructor
*/