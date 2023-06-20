#include <iostream>
#include <vector>

using namespace std;

class Widget {
public:
	Widget& operator= (const Widget &rhs) {

		// traditional way to handle self assignment? Still not exception safe
		if (this == &rhs) return *this;

		// What if the new operator here throws an exception

		// do the copying part
		return *this;
	}
};

template <typename T>
class A {
	T *ptr;
private:
	A& operator= (const A& a) {
		T* ptr_copy = ptr;
		ptr = new T(*a.ptr); // even if this throws an exception, the original ptr is still safe! (because, at that point, we haven't changed ptr yet)
		delete ptr_copy;

		return *this;
	}
};

int main(int argc, char **argv) {

	D1 d1; 

	/**
	 * What if self assignment is not handled?
	 * 
	 * Suppose the class C has a member which is a pointer.
	 * 
	 * Widget& operator= (const Widget &rhs) {
	 * 		delete ptr;	
	 * 		ptr = new T(*rhs.ptr);
	 * 
	 * 		return *this;
	 * }
	 * 
	 * Prob? If this and &rhs are same, delete ptr not deletes the resource of the current object, it also deletes
	 * the resources of &rhs, which leads to undefined behaviour
	*/

	return 0;
}