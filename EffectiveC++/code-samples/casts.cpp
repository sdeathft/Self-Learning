#include <iostream>
#include <vector>
#include <memory>

class Base {
public:
  virtual void onResize() {
    std::cout << "Base Address = " << this << "\n";
    std::cout << "on resize inside base\n";
  }
};

class Derived : public Base {
public:
  virtual void onResize() {
    // static_cast<Base>(*this).onResize(); - Dont use this
    Base::onResize();
    std::cout << "Derived Address = " << this << "\n";
    std::cout << "on resize inside derived\n";
  }
};

int main() {

  std::vector<std::shared_ptr<Base>> ptrs;

  for (auto ptr : ptrs) {
    ptr -> onResize();
  }
  // Derived d;
  // Base *bptr = &d; // allowed

  // std::cout << (bptr == &d) << std::endl;
  
  // d.onResize();

  return 0;
}
