/*
 * This lesson fixes the problem with lesson3. Again we have to use the shared_ptr to avoid making a copy.
 */

#include <stdlib.h>
#include <iostream>
#include <memory>

using namespace std;

class Vector {
    // think of this as a class containing a billion elements
    public:

        Vector() {
            cout << "constructor" << endl;
        }

        Vector(const Vector& a) {
            cout << "copy constructor. copying 1 billion elements." << endl;
        }

        Vector& operator=(const Vector& a) {
            cout << "copy assignment. copying 1 billion elements." << endl;
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

    shared_ptr<Vector> pointer_to_vector() {
        return x_;
    }
};

class B {
    public:
        shared_ptr<Vector> v;

    B(A & a) {
        v = a.pointer_to_vector();
    }
};

void f(Vector & v) {

}

int main() {
    auto p = make_shared<Vector>();
    A a{p};
    auto q = a.pointer_to_vector(); // OK: no copy constructor triggered
    A another = a;  // OK: no copy ctor triggered
    B b{a};         // OK: no copy triggered
    f(*q);          // OK: no copy triggered
    auto& z = *q;   // OK: no copy triggered
    return 0;
}

/*
Output:
constructor
destructor
*/