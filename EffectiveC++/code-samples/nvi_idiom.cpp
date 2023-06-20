#include <iostream>
#include <vector>
#include <memory>

// Usual Virtual functions

// class Base {
// public:
//     virtual int getX() const {
//         return x;
//     } 

// private:
//     int x{10};
// };

// class Derived : public Base {
// public:
//     int getX() const {
//         return x;
//     }
// private:
//     int x{20};
// };

// NVI Idiom
class Base {
public:
    int wrapperOverVirtualFunction() const {
        int ret_val = getX(); // this will use the Derived class's getX() as the base class function is virtual!
        return ret_val;
    }

private:
    virtual int getX() const {
        std::cout << "Base's getX\n";
        return 5;
    }

    int x{10};
};

class Derived : public Base {
public:
    int getX() const {      // deriving a private virtual function
        std::cout << "Derived's getX\n";
        return 10;
    }
};

int main() {
    Base *b = new Derived();
    int res = b -> wrapperOverVirtualFunction();
    std::cout << res << "\n";
    return 0;
}