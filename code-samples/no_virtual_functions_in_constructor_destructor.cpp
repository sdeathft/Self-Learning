#include <iostream>
#include <vector>

using namespace std;

class Base { // base abstract class!
public:
	Base();
	virtual void log() const = 0;

private:
	void init() {
		log();
	}
};

Base::Base() {
	init();
}

class D1 : public Base {
public:
	virtual void log() const {
		cout << "D1" << endl;
	}
};

class D2 : public Base {
public:
	virtual void log() const {
		cout << "D2" << endl;
	}
};

int main(int argc, char **argv) {

	D1 d1; 

	/**
	 * First the constructor of Base is called, which in turn calls log(), which is the one in the base class
	 * During base class construction, virtual functions never go down into derived classes
	 * Why? Because suppose we allowed to call the derived class's function. Now, that function might be using local
	 * variables from derived class, which might not be initialized yet(usually happens in the derived class's destructor)
	*/

	return 0;
}