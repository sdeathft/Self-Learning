#include <iostream>
#include <vector>
#include <memory>

class Point {
  int x, y;

public:
  Point(int x_, int y_) : x(x_), y(y_) {}
  void setX(int x_) {
    x = x_;
  }
  void setY(int y_) {
    y = y_;
  }
};

struct RectData {
  Point ulhc, lrhc;
};

class Rectangle {
  std::shared_ptr<RectData> pData;
public:
  // Don't use this -> caller can modify the value of x and y of ulhc
  // Point& upperLeft() const {
  //   return pData -> ulhc;
  // }
  // Instead, do this:
  const Point& upperLeft() const {
    return pData -> ulhc; // this won't allow modification by the caller
  }
  // Although, this is still an issue
}

/*
  Consider the following ex:
  class P {...};
  class Rect {
    P p;
  };
  class A {};

  const Rect func(const A& a);
  
Usage:
  A *a;
  const P* point = &(func(a).getPoint());

  Issue? func(a) is a temporary object, whose scope is b/w the ( and ).
  so, If func(a).getPoint() returns a handle, it becomes meaningless after the ) ends, because the  temporary is destroyed.  
*/

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
