#include <iostream>
#include <vector>
#include <memory>

class A {
public:
    void f() {
        std::cout << "A's f\n";
    }
};

class B {
private:
    void f() {
        std::cout << "B's f\n";
    }
};

class D : public A, public B {
    int x;
};

int main() {

    D d;
    // d.f(); this is an error, due to existence of two f's

    return 0;
}
