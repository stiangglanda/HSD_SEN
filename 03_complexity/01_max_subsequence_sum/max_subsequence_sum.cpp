#include <iostream>
#include <vector>

#include "maxsum1.cpp"
#include "maxsum2.cpp"
#include "maxsum3.cpp"
#include "maxsum4.cpp"

void test(size_t numOfValues, int high) {
	std::vector<int> a(numOfValues);

	for (size_t i=0; i<numOfValues; ++i)
		a[i] = rand() % high - high/2;
	
	std::cout << "maxsum1: " << maxsum1(a) << '\n';
	std::cout << "maxsum2: " << maxsum2(a) << '\n';
	std::cout << "maxsum3: " << maxsum3(a) << '\n';
	std::cout << "maxsum4: " << maxsum4(a) << '\n';
}

int main() {
	test(10, 1000);

	return 0;
}
