#include <iostream>
#include <vector>
#include <memory>

class Base {
    int x;
public:
    int getX() const {
        return x;
    }
};

class Derived : private Base {
    int y;
public:
    int getX_Y() const {
        return Base::getX() + y;
    }
};

int main() {
    return 0;
}
