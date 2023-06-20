#include <iostream>

void f(int a = 0, int b = 1) {
	// providing default values to both args
	std::cout << "a = " << a << " b = " << b << std::endl;
}

class Rational {
	int num, den;
public:
	Rational(int num_ = 0, int den_ = 1) : num(num_), den(den_) {}
	int numerator() {
		return num;
	}

	int denominator() {
		return den;
	}
};

const Rational operator* (const Rational &lhs, const Rational &rhs)

int main() {

	f();
	f(1); // replaces a!
	f(2, 3);

	return 0;
}