#include <iterator>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <ranges>

bool even(int const &x) {
	return x % 2 == 0;
}

int main() {
	std::ifstream file{"input"};
	std::ostream_iterator<int> out{std::cout, "\n"};
	
	std::ranges::copy_if(std::ranges::istream_view<int>{file}, out, even);
	
	return 0;
}

