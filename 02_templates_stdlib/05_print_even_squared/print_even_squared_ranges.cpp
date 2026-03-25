#include <iterator>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <ranges>

bool even(int const &x) {
	return x % 2 == 0;
}

int square(int const &x) {
	return x*x;
}

int main() {
	std::ifstream file{"input"};

	auto values = std::views::istream<int>(file) |
	              std::views::filter(even) |
	              std::views::transform(square);
	
	std::ranges::copy(values, std::ostream_iterator<int>{std::cout, "\n"});

	return 0;
}

