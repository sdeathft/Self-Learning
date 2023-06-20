#include <iostream>
#include <string>
// #include <vector>
#include <memory>

class A; // no definition

/*
  One way to minimize dependencies is to use the "Pimpl" idiom
  
  Inside class_impl.h - independent of other dependencies that the actual class might need:
  class Impl {
    // write the actual implementation
  };
  
  inside class.h:
  class Actual {
  public:
    std::shared_ptr<Impl>;
  };
  
  How do the functions work?
  Ex:
  Actual::Actual(params) : Impl(params) {}
  T Actual::get_param() {
    Impl -> get_param();
  }

  Use declarations as much as possible; Put the declarations and definitions in separate files as shown above.
*/

class Date;
class Address;

class Abstract_class {
  int a, b;
public:
  Abstract_class(int a_, int b_) {
    a = a_;
    b = b_;
  }

  virtual void func1() = 0;

  virtual void func2() {
    std::cout << "func 2" << std::endl;
  }
};

int main() {
  Abstract_class* abc;

  int x;
  // A a; // this is a compilation error! Why? How does the compiler know the amount of memory it has to allocate in the stack?

  A* a; // this compiles, because it's just a pointer
  
  return 0;
}
