#include <iostream>

#include "complex.h"

int main() {
	Complex c1, c2{1}, c3{1, 1};

	std::cout << c1 + c2 << '\n';

	std::cout << c1 << " " << c2 << " " << c3 << '\n';
	std::cout << (c1 == c2) << '\n';
	std::cout << (c1 == c1) << '\n';
	std::cout << (Complex(1, 1) == c3) << '\n';
	std::cout << c1 + 3 << '\n';
	std::cout << 3 + c1 << '\n';

	return 0;
}

