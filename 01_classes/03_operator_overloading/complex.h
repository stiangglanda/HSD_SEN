#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
	friend Complex operator+(int lhs, Complex const &rhs);
	friend std::ostream &operator<<(std::ostream &o, Complex const&c);

private:
	int r, i;

public:
	Complex(int _r = 0, int _i = 0) : r{_r}, i{_i} {}
	~Complex() {}

	// § 11.3.5: No implicit user-defined type conversions are applied to
	//  the left-hand side of a . (or a ->).
	//  Daher wird, solange operator+ als Complex::operator+(Complex const&)
	//  und nicht als operator+(Complex const &, Complex const &) definiert
	//  ist, in c+3 "3" automatisch umgewandelt, in 3+c aber nicht.
	Complex operator+(Complex const &rhs) const {
		return Complex(r+rhs.r, i+rhs.i);
	}

	bool operator==(Complex const &rhs) const {
		return r==rhs.r && i == rhs.i;
	}
};

Complex operator+(int lhs, Complex const &rhs);
std::ostream &operator<<(std::ostream &o, Complex const&c);

#endif // COMPLEX_H

