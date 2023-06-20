# 1 "inline_functions.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "inline_functions.cpp"
# 27 "inline_functions.cpp"
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
