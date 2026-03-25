#include <iterator>
#include <fstream>
#include <algorithm>
#include <iostream>

bool even(int const &x) {
	return x % 2 == 0;
}

int main() {
	std::ifstream file{"input"};
	std::ostream_iterator<int> out{std::cout, "\n"};
	
	std::copy_if(std::istream_iterator<int>{file}, std::istream_iterator<int>{}, out, even);
	
	return 0;
}

