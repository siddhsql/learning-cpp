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

// lesson: when returning a local variable, do not use & in the function signature
// i.e., use Vector f() not Vector & f()
Vector f() {
    Vector v;
    return v;
}

int main() {
    // auto &z will give following error:
    // see: https://stackoverflow.com/questions/52115902/non-const-lvalue-reference-to-type-cannot-bind-to-a-temporary-of-type
    // auto const& z will work
    auto z = f();
    return 0;
}

/*
Output:
constructor
destructor
*/