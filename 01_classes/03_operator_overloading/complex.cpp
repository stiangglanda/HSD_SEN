#include "complex.h"

Complex operator+(int lhs, Complex const &rhs) {
	return Complex(lhs+rhs.r, rhs.i);
}

std::ostream &operator<<(std::ostream &o, Complex const&c) {
	o << "(" << c.r << "," << c.i << ")";
	return o;
}

