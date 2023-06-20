#include <iostream>
#include <vector>

template<typename T>
class WidgetImpl {
  T a, b, c;
  std::vector<T> v;
public:
};

template <typename T>
class Widget {
  WidgetImpl<T> *ptr;
public:
  Widget(const Widget<T> &rhs);
  Widget& operator= (const Widget<T> &rhs) {
    *ptr = *(rhs.ptr); // inefficient!
    return *this;
  }

  void swap(Widget<T> &rhs) {
    std::swap(ptr, rhs.ptr);
  }
};

namespace std {
  template <typename T>
  void swap(Widget<T> &a, Widget<T> &b) {
    // swap(a.ptr, b.ptr); // Won't compile, as ptr is a private variable.
    a.swap(b); // will compile!
  }
}

int main() {

  
  return 0;
}
