// #include <iostream>
// #include <vector>
// #include <memory>

/*
  inline functions for large functions increase the size of code; 
  More pages required => reduced instruction cache hit-rate, and additional performance penalties
*/

// inline void f(int a, int b) {
//   std::cout << "hello inline\n";
// }

// struct Person {
//   inline int age() const {
//     return Age;
//   }
// private:
//   int Age;
// };

// template <typename T>
// inline const T& max(T &a, T &b) {
//   return a < b ? b : a;
// }

/*
  Don't inline constructors or destructors; 

  Let's say Derived's constructor is inlined. Although the constructor of Derived seems empty, it tries to initialize the members of the derived class, calling the base's destructor if the construction throws. Same holds for destructors as well.
*/

class Base {
public:
  Base() {}
  ~Base() {}

private:
  int a, b;
};

class Derived : public Base {
  int c, d;
public:
  Derived() {}

  ~Derived() {}
};

int main() {

  Derived D;
  
  return 0;
}
