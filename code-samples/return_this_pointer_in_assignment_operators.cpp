#include <iostream>
#include <vector>

// Trying to use Emacs here 

using namespace std;

class Widget {
public:
	Widget& operator= (const Widget &rhs) {
		// do the copying part
		return *this;
	}
};

int main(int argc, char **argv) {

	Widget w; 

	/**
	 * First the constructor of Base is called, which in turn calls log(), which is the one in the base class
	 * During base class construction, virtual functions never go down into derived classes
	 * Why? Because suppose we allowed to call the derived class's function. Now, that function might be using local
	 * variables from derived class, which might not be initialized yet(usually happens in the derived class's destructor)
	*/

	
	
	return 0;
}
