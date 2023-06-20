#include <iostream>
#include <vector>
#include <memory>

// class Base {
//     int x;
// public:
//     virtual void mf1() = 0;
//     virtual void mf1(int) {}
//     virtual void mf2() {}
//     void mf3() {}
//     void mf3(double) {}
// };

// class Derived : public Base {
// public:
//     virtual void mf1() {} // hides mf1 of Base class
//     void mf3() {} // hides mf3 class of Base
//     void mf4() {}
// };

class C {
public:
    virtual void f() = 0;
};

void C::f() {
    std::cout << "definition for pure virtual function\n";
}

class D : public C {
public:
    void f() {
        std::cout << "definition in class\n"; // if you want your own implementation
        C::f(); // if you just want to use the default
    }
};

int main() {
    D d;
    d.f();
    // Derived d;
    // d.mf1();
    // // d.mf1(10); // this is not correct, as mf1 of derived hides the mf1's of the Base class
    // d.Base::mf1(10); // one way to call Base's mf1
    return 0;
}
