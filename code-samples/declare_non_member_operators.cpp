#include <iostream>

void f(int a = 0, int b = 1) {
	// providing default values to both args
	std::cout << "a = " << a << " b = " << b << std::endl;
}

class Rational {
	int num, den;
public:
	Rational(int num_ = 0, int den_ = 1) : num(num_), den(den_) {}
	int numerator() const {
		return num;
	}

	int denominator() const {
		return den;
	}
};

const Rational operator+ (const Rational &lhs, const Rational &rhs) {
  return Rational(lhs.numerator() * rhs.denominator() + lhs.denominator() * rhs.numerator(), lhs.denominator() * rhs.denominator();
}

const Rational operator* (const Rational &lhs, const Rational &rhs) {
	return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

int main() {

	f();
	f(1); // replaces a!
	f(2, 3);

	Rational oneFourth{1, 4};
	std::cout << oneFourth.numerator() << " " << oneFourth.denominator() << std::endl;

	Rational result = oneFourth * 2;
	std::cout << result.numerator() << " " << result.denominator() << std::endl;

	return 0;
}
