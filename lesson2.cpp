/*
 * This lesson is followup to lesson1 and shows how to mimic Java references in C++.
 * Hint: use shared_ptr
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
    shared_ptr<Vector> x;

    A(shared_ptr<Vector> a) : x(a) {
        
    }
};

int main() {
    auto p = make_shared<Vector>();
    A q{p}; // OK: no copy of Vector is triggered
    return 0;
}

/*
Output:
constructor
destructor
*/