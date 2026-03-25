#include <iterator>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>

bool even(int const &x) {
	return x % 2 == 0;
}

int square(int const &x) {
	return x*x;
}

int main() {
	std::ifstream file{"input"};
	std::vector<int> filtered;
	
	std::copy_if(std::istream_iterator<int>{file}, std::istream_iterator<int>{}, std::back_inserter(filtered), even);
	std::transform(begin(filtered), end(filtered), begin(filtered), square);
	std::copy(begin(filtered), end(filtered), std::ostream_iterator<int>{std::cout, "\n"});
	
	return 0;
}

