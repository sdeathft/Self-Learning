#include <iostream>
#include <vector>
#include <memory>

/*
  Exception Safety requires:
  - no leak of resources
  - Don't allow data structures to be corrupted

  Prefer the following function:
  void f() {
    T* temp = new T();
    delete curr;
    curr = temp;
  }

  to 

  void f() {
    delete curr;
    curr = new T();
  }

  Even better will be to use:
  Assume curr is of type std::shared_ptr<T>

  void f() {
    curr.reset(new T()); // reset will call delete; 
                         // If new throws, then reset will never be called
			 // So, delete will also be never called.
  }

  We're using the Copy-and-Swap paradigm.

  We create the copy first, do all the updates on it, and finally swap it with the original. 
  This way, we'll never be modifying the original if any operation during the copy throws.

*/

int main() {

  
  
  return 0;
}
