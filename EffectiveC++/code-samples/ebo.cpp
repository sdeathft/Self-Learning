#include <iostream>
#include <vector>
#include <memory>

class Empty {
};

class D1 { // this should be 4+1 = 5, but becomes 8 due to padding.
    int x;
    Empty e;
};

class D2 : private Empty { // size of this is 4! - Useful for space optimization, 100% better
    int x;
};

int main() {

    std::cout << "sizeof int = "  << sizeof(int) << std::endl;
    std::cout << "sizeof Empty = " << sizeof(Empty) << std::endl;
    std::cout << "sizeof D1 = " << sizeof(D1) << std::endl;
    std::cout << "sizeof D2 = " << sizeof(D2) << std::endl;

    return 0;
}
